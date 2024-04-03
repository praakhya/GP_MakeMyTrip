#include "User.hpp"

User::User() {
    if (getuid()==0) {
        setUsername(getlogin());
        setType("ADMIN");
    }
    else {
        setUsername(getlogin());
        setType("CUSTOMER");
    }
}