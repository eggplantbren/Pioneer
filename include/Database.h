#ifndef Pioneer_Database_h
#define Pioneer_Database_h

#include <sqlite_modern_cpp/hdr/sqlite_modern_cpp.h>
#include <vector>

namespace Pioneer
{

class Database
{
    private:
        sqlite::database db;

        void pragmas();
        void clear();
        void create_tables();

    public:
        Database();

        // Save a particle
        void save_particle(const std::vector<double>& scalars);

};

} // namespace

#endif

