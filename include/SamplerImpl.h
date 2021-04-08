#ifndef Pioneer_SamplerImpl_h
#define Pioneer_SamplerImpl_h

#include "Constants.h"

namespace Pioneer
{

template<typename T>
Sampler<T>::Sampler()
:epoch(0)
{
    std::cout << "Initialising sampler." << std::flush;

    std::cout << "\n  Generating and evaluating particles." << std::flush;
    particles.reserve(num_particles);
    scalars.reserve(num_particles);
    logps.reserve(num_particles);
    for(int i=0; i<num_particles; ++i)
    {
        T t(rng);
        std::vector<double> ss = t.scalars();
        double logp = target.evaluate(ss);

        particles.emplace_back(std::move(t));
        scalars.emplace_back(std::move(ss));
        logps.push_back(logp);
    }

    std::cout << "\nDone.\n" << std::endl;

    save_and_update();
}



template<typename T>
void Sampler<T>::save_particles()
{
    for(int i=0; i<num_particles; ++i)
        database.save_particle(epoch, scalars[i]);
}




template<typename T>
void Sampler<T>::update_target()
{
    target.update(database);
    for(int i=0; i<num_particles; ++i)
        logps[i] = target.evaluate(scalars[i]);
    ++epoch;
}


template<typename T>
void Sampler<T>::save_and_update()
{
    std::cout << "Saving particles and updating target distribution.";
    std::cout << std::flush;
    save_particles();
    update_target();
    std::cout << "\nDone.\n" << std::endl;
}

template<typename T>
void Sampler<T>::explore(int mcmc_steps)
{
    std::cout << "Exploring." << std::flush;

    int accepted = 0;
    for(int i=0; i<mcmc_steps; ++i)
    {
        // Choose a particle
        int k = rng.rand_int(num_particles);

        T proposal_t = particles[k];
        double logh = proposal_t.perturb(rng);
        if(rng.rand() <= exp(logh))
        {
            auto proposal_scalars = proposal_t.scalars();
            double proposal_logp = target.evaluate(proposal_scalars);
            if(rng.rand() <= exp(proposal_logp - logps[k]))
            {
                // Accept
                particles[k] = proposal_t;
                scalars[k] = proposal_scalars;
                logps[k] = proposal_logp;
                ++accepted;
            }
        }

    }

    std::cout << "\nDone. Acceptance rate = ";
    std::cout << accepted << '/' << mcmc_steps << ".\n" << std::endl;

    save_and_update();
}



} // namespace

#endif

