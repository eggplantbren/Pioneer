#ifndef Pioneer_Target_h
#define Pioneer_Target_h

#include <Database.h>
#include <vector>

namespace Pioneer
{

class Target
{
    private:
        std::vector<std::vector<double>> scalars;

    public:
        Target() = default;
        double evaluate(const std::vector<double>& _scalars) const;
        void update(Database& database);
};

} // namespace

#endif

