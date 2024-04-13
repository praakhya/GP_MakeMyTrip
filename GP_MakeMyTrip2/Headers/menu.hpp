#ifndef __MENU_H__
#define __MENU_H__
#include "Utils.hpp"
#include "Pair.hpp"

template <class T>
class Menu
{
public:
  typedef Map<std::string, void (T::*)()> MapType; //the value is a method that is bound to an instance of a particular class
  typedef Pair<std::string, void (T::*)()> PairType;
  template <typename... MapPairType>
  Menu(T &target, bool returnIsExit, MapPairType... pairs) //target is the class in which the method exists
      : target(target), returnIsExit(returnIsExit)
  {
    addMenuItem(pairs...);
  }
  void run()
  {
    std::string strChoice;
    int choice;
    do
    {

      std::cout << "Choose an option:-\n"
                << std::endl;
      for (int i = 0; i < menuMap.size(); ++i)
      {
        std::cout << i + 1 << ". " << menuMap.get(i)->key() << std::endl;
      }
      std::cout << menuMap.size() + 1 << (returnIsExit ? ". Exit" : ". Return") //The class allows certain menus to exit the program and others to just exit current scope
                << std::endl;
      std::getline(std::cin, strChoice);
      choice = std::stoi(strChoice);
//      std::cout << "Choice entered :" << strChoice << ' ' << choice << std::endl;
      if (choice < 1 && choice > menuMap.size() + 1)
      {
        std::cout << "Invalid option. Try Again\n";
        continue;
      }
      else if(choice >= 1 && choice <= menuMap.size() + 1)
      {

        if (choice == menuMap.size() + 1)
        {
          /** Here we are choosing the last element in the menu. It is hardcoded
           * to be return from child menu to parent.
           */
          if (returnIsExit)
          {
            std::cout << "Exiting..." << std::endl;
            exit(0);
          }
          else
          {
            return;
          }
        }
        else {

        void (T::*methodPtr)() = menuMap.get(choice - 1)->value();
        (target.*methodPtr)(); //calling the function pointer
        }
      }
      else {
        std::cout << "Invalid choice entered " << choice << std::endl;
      }
    } while (choice > 0 && choice <= menuMap.size() + 1);
  }

private:
  T &target;
  Map<std::string, void (T::*)()> menuMap; //a map of strings and function pointers
  bool returnIsExit;

  template <typename T1>
  void addMenuItem(const T1 &pair1)
  {
    menuMap.insert(pair1);
  }

  template <typename T1, typename... T2>
  void addMenuItem(const T1 &pair1, const T2 &...pairs) //A variadic template to add multiple menu items
  {
    menuMap.insert(pair1);
    if (sizeof...(pairs) > 0)
    {
      addMenuItem(pairs...);
    }
  }
};
#endif // __MENU_H__