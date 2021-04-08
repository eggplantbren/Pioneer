#ifndef Pioneer_Compare_h
#define Pioneer_Compare_h

#include <functional>
#include <vector>

namespace Pioneer
{

const std::function<bool(double, double)> gt = [](double x, double y)
                                                 { return x > y; };
const std::function<bool(double, double)> geq = [](double x, double y)
                                                 { return x >= y; };

bool all_below(const std::vector<double>& xs,
               const std::vector<double>& ys, bool strict=true);

} // namespace

#endif

