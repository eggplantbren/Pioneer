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

        // Transaction control
        void begin();
        void commit();

        // Save a particle
        void save_particle(int epoch, const std::vector<double>& scalars);

        // Load scalars
        std::vector<std::vector<double>> load_scalars();

};

} // namespace

#endif

