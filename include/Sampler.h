#ifndef Pioneer_Sampler_h
#define Pioneer_Sampler_h

#include <Tools/RNG.hpp>
#include <vector>

namespace Pioneer
{

template<typename T>
class Sampler
{
    private:

        // RNG to use
        Tools::RNG rng;

        // The particles and their scalars
        std::vector<T> particles;
        std::vector<std::vector<double>> scalars;


    public:
        Sampler();


};

} // namespace

#endif

#include "SamplerImpl.h"
