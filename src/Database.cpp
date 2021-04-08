#include "Database.h"
#include "Constants.h"

namespace Pioneer
{

Database::Database()
:db(db_filename)
{
    pragmas();

    db << "BEGIN;";
    clear();
    create_tables();
    db << "COMMIT;";
}


void Database::pragmas()
{
    db << "PRAGMA FOREIGN_KEYS = 0;";
    db << "PRAGMA JOURNAL_MODE = WAL;";
    db << "PRAGMA SYNCHRONOUS = 0;";
}


void Database::clear()
{
    db << "DROP TABLE IF EXISTS scalars;";
    db << "DROP TABLE IF EXISTS particles;";
}


void Database::create_tables()
{
    db << "CREATE TABLE IF NOT EXISTS particles\
(id INTEGER NOT NULL PRIMARY KEY);";

    db << "CREATE TABLE IF NOT EXISTS scalars\
(particle_id INTEGER NOT NULL REFERENCES particles (id),\
 scalar      INTEGER NOT NULL,\
 value       REAL NOT NULL,\
 PRIMARY KEY (particle_id, scalar))\
WITHOUT ROWID;";

}


void Database::save_particle(const std::vector<double>& scalars)
{
    int particle_id;
    db << "INSERT INTO particles DEFAULT values;";
    db << "SELECT LAST_INSERT_ROWID();" >> particle_id;

    for(size_t i=0; i<scalars.size(); ++i)
    {
        db << "INSERT INTO scalars VALUES (?, ?, ?);"
           << particle_id << i << scalars[i];
    }
}


} // namespace

