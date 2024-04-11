#include "database.hpp"

Database* Database::instance = 0;
Database* Database::getInstance() {
    
    if (Database::instance==NULL) {
        Database::instance = new Database();
    }
    return Database::instance;
}

int Database::openDB() {
    int rc = sqlite3_open("../makeMyTrip.db", &db);
    char* msg = "Error opening DB";
    handleError(rc, msg);
    return rc;
}
void Database::closeDB() {
    sqlite3_close(db);
}
void Database::handleError(int rc, char* errorMsg) {
    if (rc != SQLITE_OK) { 
        std::cerr << "Error! " << std::endl; 
        sqlite3_free(errorMsg); 
    } 
    else
        std::cout << "Table created Successfully" << std::endl; 
    closeDB();
    exit(0);
}
int Database::execute(std::string query) {
    char* messageError; 
    int rc = sqlite3_exec(db, query.c_str(), NULL, 0, &messageError);
    handleError(rc,messageError);
}