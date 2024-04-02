#ifndef __MENU_H__
#define __MENU_H__
#include "Utils.hpp"

template <class T>
class Menu
{
public:
  typedef Map<std::string, void (T::*)()> MapType;
  typedef Pair<std::string, void (T::*)()> PairType;
  template <typename... MapPairType>
  Menu(T &target, bool returnIsExit, MapPairType... pairs)
      : target(target), returnIsExit(returnIsExit)
  {
    addMenuItem(pairs...);
  }
  void run()
  {
    int choice;
    do
    {

      std::cout << "Choose an option:-\n"
                << std::endl;
      for (int i = 0; i < menuMap.size(); ++i)
      {
        std::cout << i + 1 << ". " << menuMap.get(i)->key() << std::endl;
      }
      std::cout << menuMap.size() + 1 << (returnIsExit ? ". Exit" : ". Return")
                << std::endl;
      std::cin >> choice;
      if (choice < 1 && choice > menuMap.size() + 1)
      {
        std::cout << "Invalid option. Try Again\n";
        continue;
      }
      else
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
        void (T::*methodPtr)() = menuMap.get(choice - 1)->value();
        (target.*methodPtr)();
      }
    } while (choice > 0 && choice <= menuMap.size() + 1);
  }

private:
  T &target;
  Map<std::string, void (T::*)()> menuMap;
  bool returnIsExit;

  template <typename T1>
  void addMenuItem(const T1 &pair1)
  {
    menuMap.insert(pair1);
  }

  template <typename T1, typename... T2>
  void addMenuItem(const T1 &pair1, const T2 &...pairs)
  {
    menuMap.insert(pair1);
    if (sizeof...(pairs) > 0)
    {
      addMenuItem(pairs...);
    }
  }
};
#endif // __MENU_H__