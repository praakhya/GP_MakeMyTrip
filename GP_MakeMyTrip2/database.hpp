#include <iostream>
#include <string>
#include <sqlite3.h> 
class Database {
    public:
    static Database* instance;
    static Database* getInstance();
    int openDB();
    void closeDB();
    void handleError(int rc, char* errorMsg);
    int execute(std::string query);
    private:
    sqlite3 *db;

};