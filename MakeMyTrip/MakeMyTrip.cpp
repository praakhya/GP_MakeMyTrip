#include "../MakeMyTrip/MakeMyTrip.hpp"
void book(){}

MakeMyTrip::MakeMyTrip(){
    Map<std::string, VoidFunctionPointer>* choices = new Map<std::string, VoidFunctionPointer>();
    choices->pair_insert("Create a Booking",&book);
    choices->print();
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
void MakeMyTrip::runCustomer() {
    std::cout << "Welcome to Make My Trip" << std::endl;
    std::string choice = "";
    while (choice.compare("")==0) {
        std::cout << "Choose an option:-\n" << std::endl;
        for (int i=0; i<choices->size(); ++i) {
            std::cout << choices->get(i)->key() << std::endl;
        }
        std::cin >> choice;
        if (choice.compare("exit")==0) {
            std::cout << "Thank you for visiting\n";
            return;
        }
    }
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