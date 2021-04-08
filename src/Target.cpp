#include "Target.h"
#include "Compare.h"
#include <iostream>

namespace Pioneer
{


double Target::evaluate(const std::vector<double>& _scalars) const
{
    int ucc = 0;
    for(const auto& ss: scalars)
    {
        if(all_below(_scalars, ss))
            ++ucc;
    }
    return -double(ucc);
}

void Target::update(Database& database)
{
    std::vector<std::vector<double>> updated = database.load_scalars();
    std::swap(updated, scalars);
}

} // namespace

