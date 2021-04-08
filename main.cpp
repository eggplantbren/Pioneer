#include <iostream>
#include <Example.h>
#include <Sampler.h>

using namespace Pioneer;

int main()
{

    Sampler<Example> sampler;
    sampler.explore(10000);

    return 0;
}

