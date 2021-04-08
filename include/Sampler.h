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

        // The particles and their scalars
        std::vector<T> particles;
        std::vector<std::vector<double>> scalars;

        // Target distribution and its evaluations
        Target target;
        std::vector<double> logps;

        // Update target distribution
        void update_target();


    public:

        // Initialise sampler
        Sampler();

        // Do some exploration
        void explore(int mcmc_steps);
};

} // namespace

#endif

#include "SamplerImpl.h"
