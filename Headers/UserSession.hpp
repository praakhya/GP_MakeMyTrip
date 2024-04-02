#include <string>
#include <unistd.h>
#include "Utils.hpp"



class UserSession {
    std::string getUserType(){
        if (getuid() == 0) {
            return "ADMIN";
        }
        return "CUSTOMER";
    }
    std::string userType;
    public:
    UserSession(){
        userType = getUserType().c_str();
    }
};