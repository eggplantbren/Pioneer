#ifndef Pioneer_Database_h
#define Pioneer_Database_h

#include <sqlite_modern_cpp/hdr/sqlite_modern_cpp.h>

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

};

} // namespace

#endif

