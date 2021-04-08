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



} // namespace

