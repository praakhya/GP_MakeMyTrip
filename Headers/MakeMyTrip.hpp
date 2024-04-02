#include <iostream>
#include <string>
#include <unistd.h>

#include "Utils.hpp"
#include "BookingResourceManager.hpp"

class MakeMyTrip {
    void runCustomer();
    void runAdmin();
    int runMenu();
    Map<std::string, VoidFunctionPointer>* choices;
    public:
        static void executeMenu(const Map<std::string, VoidFunctionPointer>& menu);
        MakeMyTrip();
        void run();

};

