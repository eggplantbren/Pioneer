#include <iostream>
#include <Example.h>
#include <Sampler.h>

using namespace Pioneer;

int main()
{

    Sampler<Example> sampler;

    for(int i=0; i<100; ++i)
        sampler.explore(10000);

    return 0;
}

