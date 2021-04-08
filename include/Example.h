#ifndef Pioneer_Example_h
#define Pioneer_Example_h

#include <Tools/RNG.hpp>
#include <vector>

namespace Pioneer
{

class Example
{
    private:
        std::vector<double> xs;

    public:
        Example(Tools::RNG& rng);
        double perturb(Tools::RNG& rng);
        std::vector<double> scalars() const;
};

} // namespace

#endif

