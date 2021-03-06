#ifndef Pioneer_Sampler_h
#define Pioneer_Sampler_h

#include <Database.h>
#include <Target.h>
#include <Tools/RNG.hpp>
#include <vector>

namespace Pioneer
{

template<typename T>
class Sampler
{
    private:

        // Output database
        Database database;

        // RNG to use
        Tools::RNG rng;

        // Epoch counter
        int epoch;

        // The particles and their scalars
        std::vector<T> particles;
        std::vector<std::vector<double>> scalars;

        // Target distribution and its evaluations
        Target target;
        std::vector<double> logps;

        // Save particles
        void save_particles();

        // Update target distribution
        void update_target();

        // Just do the above two functions, with some logging
        void save_and_update();


    public:

        // Initialise sampler
        Sampler();

        // Do some exploration
        void explore(int mcmc_steps);
};

} // namespace

#endif

#include "SamplerImpl.h"
