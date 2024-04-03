#include <unistd.h>
#include <string>

class User {
    std::string username;
    std::string type;
    public:
    User();
    inline std::string getUsername() {
        return username;
    }
    inline void setUsername(std::string username) {
        this->username = username;
    }
    inline std::string getType() {
        return type;
    }
    inline void setType(std::string type) {
        this->type = type;
    }
};