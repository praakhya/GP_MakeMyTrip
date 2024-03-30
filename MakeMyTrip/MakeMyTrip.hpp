#include <iostream>
#include <string>
#include <unistd.h>

#include "../Utils/Utils.hpp"
class MakeMyTrip {
    void runCustomer();
    void runAdmin();
    Map<std::string, VoidFunctionPointer>* choices;
    public:
        MakeMyTrip();
        void run();

};



