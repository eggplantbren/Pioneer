#include "Target.h"
#include "Compare.h"

namespace Pioneer
{


double Target::evaluate(const std::vector<double>& _scalars) const
{
    int ucc = 0;
    for(const auto& ss: scalars)
    {
        if(all_below(ss, _scalars))
            ++ucc;
    }
    return -double(ucc);
}

} // namespace

