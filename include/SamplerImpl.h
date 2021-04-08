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
    for(int i=0; i<num_particles; ++i)
    {
        T t(rng);
        scalars.emplace_back(t.scalars());
        particles.emplace_back(std::move(t));
    }

    std::cout << "done." << std::endl;
}


} // namespace

#endif

