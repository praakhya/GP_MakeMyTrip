#include "../MakeMyTrip/MakeMyTrip.hpp"
#include "../BookingResourceManager/BookingResourceManager.hpp"

void startHotelBooking() {

}
void startHomestayBooking() {

}
void startVillaBooking() {

}
void startAccomodation(){

    Map<std::string, VoidFunctionPointer> accomodationSubMenu;
    accomodationSubMenu.insert(Pair<std::string, VoidFunctionPointer>("Hotel", &startHotelBooking),
    Pair<std::string, VoidFunctionPointer>("Homestay", &startHomestayBooking),
    Pair<std::string, VoidFunctionPointer>("Villa", &startVillaBooking)
    );
    MakeMyTrip::executeMenu(accomodationSubMenu);
}

void startTransportation(){}
void startManager(){}
void exitApp(){exit(0);}
typedef Pair<int, std::string> IntStringPair;
MakeMyTrip::MakeMyTrip(){
    choices = new Map<std::string, VoidFunctionPointer>();
    choices->insert(
        Pair<std::string, VoidFunctionPointer>
        ("Accomadation",&startAccomodation), 
        Pair<std::string, VoidFunctionPointer>
        ("Transportation",&startTransportation),
        Pair<std::string, VoidFunctionPointer>
        ("Manage Bookings",&startManager),
        Pair<std::string, VoidFunctionPointer>
        ("Exit",&exitApp)
    );
}
void MakeMyTrip::run(){
    if (getuid()) {
        this->runCustomer();
    }
    else {
        this->runAdmin();
    }
}
void MakeMyTrip::runAdmin() {
    std::cout << "Run admin" << std::endl;
}
int MakeMyTrip::runMenu() {
    int choice;
    std::cout << "Choose an option:-\n" << std::endl;
    for (int i=0; i<choices->size(); ++i) {
        std::cout << i+1 << ". " << choices->get(i)->key() << std::endl;
    }
    std::cin >> choice;
    return choice;
}
void MakeMyTrip::runCustomer() {
    std::cout << "Welcome to Make My Trip" << std::endl;
    int choice = runMenu();
    while (1) {
        if (choice<1 && choice>choices->size()) {
            std::cout << "Invalid option. Try Again\n";
            continue;
        }
        Pair<std::string, VoidFunctionPointer>* pair = choices->get(choice-1);
        pair->value()();
        choice = runMenu();

    }
}


void MakeMyTrip::executeMenu(const Map<std::string, VoidFunctionPointer>& menu) {

    int choice;
    do {

    std::cout << "Choose an option:-\n" << std::endl;
    for (int i=0; i<menu.size(); ++i) {
        std::cout << i+1 << ". " << menu.get(i)->key() << std::endl;
    }
    std::cout << menu.size() + 1 << ". Return" << std::endl;
    std::cin >> choice;
    if (choice<1 && choice > menu.size() + 1) {
        std::cout << "Invalid option. Try Again\n";
        continue;
    }
    else {

        if (choice == menu.size() + 1) {
            /** Here we are choosing the last element in the menu. It is hardcoded to be
             * return from child menu to parent.
            */
            return;
        }
        Pair<std::string, VoidFunctionPointer>* pair = menu.get(choice-1);
        pair->value()();
    }
    }
    while(choice > 0 && choice <= menu.size() + 1);
}
int main() {
    MakeMyTrip m = MakeMyTrip();
    m.run();
    /* Map<int,int>* m = new Map<int,int>();
    std::cout << "insert 1\n";
    m->pair_insert(1,2);
    m->print();
    std::cout << "insert 3\n";
    m->pair_insert(1,3);
    m->pair_insert(1,4);
    m->pair_insert(2,5);
    m->print();
    std::cout << "erase 1\n";
    m->erase(1);
    m->print();
    m->get(0)->print();
    std::cout << "key: " <<  m->get(0)->key() << std::endl; */

}