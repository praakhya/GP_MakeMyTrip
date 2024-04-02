#include "menu.hpp"
#include <iostream>

class TestTarget {
public:
  void method1() { std::cout << "Method 1" << std::endl; }
  void method2() { std::cout << "Method 2" << std::endl; }
  void method3() { std::cout << "Method 3" << std::endl; }
};

int main() {
  TestTarget t;
  {

    Menu<TestTarget> menu1(
        t, false, Menu<TestTarget>::PairType("Item 1", &TestTarget::method1),
        Menu<TestTarget>::PairType("Item 2", &TestTarget::method2),
        Menu<TestTarget>::PairType("Item 3", &TestTarget::method3));
    menu1.run();
  }
  {

    Menu<TestTarget> menu1(
        t, true, Menu<TestTarget>::PairType("Item 1", &TestTarget::method1),
        Menu<TestTarget>::PairType("Item 2", &TestTarget::method2),
        Menu<TestTarget>::PairType("Item 3", &TestTarget::method3));
    menu1.run();
  }
}
