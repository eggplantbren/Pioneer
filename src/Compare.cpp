#include "Compare.h"
#include <cassert>

namespace Pioneer
{

bool all_below(const std::vector<double>& xs,
               const std::vector<double>& ys, bool strict)
{
    assert(xs.size() == ys.size());

    const auto* f = (strict)?(&geq):(&gt);

    for(size_t i=0; i<xs.size(); ++i)
    {
        if((*f)(xs[i], ys[i]))
            return false;
    }

    return true;
}

}
