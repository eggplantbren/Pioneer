#ifndef Pioneer_Sampler_h
#define Pioneer_Sampler_h

#include <vector>

namespace Pioneer
{

template<typename T>
class Sampler
{
    private:
        std::vector<T> particles;


    public:
        Sampler();


};

} // namespace

#endif

#include "SamplerImpl.h"
