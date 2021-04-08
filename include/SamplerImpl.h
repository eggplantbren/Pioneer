#ifndef Pioneer_SamplerImpl_h
#define Pioneer_SamplerImpl_h

#include "Constants.h"

namespace Pioneer
{

template<typename T>
Sampler<T>::Sampler()
{
    std::cout << "Initialising sampler..." << std::flush;

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

    std::cout << "done." << std::endl;
}


} // namespace

#endif

