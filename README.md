# MakeMyTrip and Generic Programming
---
## Description
My project is a basic implementation of the “Make My Trip” application that utilises some generic programming concepts. It has features such as different user types, accommodation bookings and modifying the accommodations database etc..
- Version 1 is in base path (moved away from because of unsuitability to templatization and unnecessary complexity)
- Version 2 is in GP_MakeMyTrip2

## List of Generic Programming Features
- [x] [Variadic Templates](###variadic-templates)
- [x] [Fold Expression Templates](###fold-expression)
- [x] [Template Specialsation](###template-specialisation)
- [x] [Template Friendship](###template-friendship)
- [x] [No STLs used](###STL)
### Variadic Templates
This application uses menus and vectors heavily. Both of these classes use variadic templates.
The Menu class uses variadic templates to be able to add a variable number of menu items to display. The vector class uses variadic templates to be able to push a variable number of elements in the push_back method and during vector instantiation in the constructor.
- [Link to example 1 gist](https://gist.github.com/praakhya/ea3e0dd95250cdb462561499737265bb)
- [Link to example 2 gist](https://gist.github.com/praakhya/f8d394b54d553c1f5cde5a37dac922fc)
```c++
//Example 1: Variadic Templates in the Vector class
template <typename... Types>
void push_back(T a, Types... b)
{
    this->vector[endIndex++] = a;
    if (sizeof...(b) > 0)
    {
        push_back(b...);
    }
}
void push_back(T a)
{
    this->vector[endIndex++] = a;
}

//Example 2: Variadic Templates in Menu class
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
```
### Fold Expression
The fold expression has been used to concatenate strings.
- [Link to example gist](https://gist.github.com/praakhya/0e9403d2fa888564d3c9b041cdc9093f)
```c++
template<typename... Args>
std::string concat(Args&& ... args)
{   
    std::ostringstream stream;
    ((stream << args << ' '), ...);
    return stream.str();
}
```
### Template Specialisation
There exists a template called “compare” that aids in comparing different types of objects based on different conditions.
The compare function template has been specialised to be able to compare two entities based on their IDs
- [Link to compare function gist](https://gist.github.com/praakhya/88b2191146d50f0635de04b126f47fc9)
- [Link to the specialised template gist](https://gist.github.com/praakhya/2787efa916432a808b9ae615621e9e6d)
```c++
//Compare function
#include <iostream>

template <typename T, typename K>
bool compare(const T &lhs, const K &rhs)
{
    return lhs == rhs;
}

//Specialisation
template <>
bool compare<>(const Homestay &lhs, const int &rhs) {
  return lhs.id == rhs;
}
```
### Template friendship
The specialisation of the above compare function is a friend of each of the entity classes (such as Hotel, Villa, Homestay) 
```c++
friend bool compare<>(const Hotel &lhs, const int &rhs);
```
### STL
No STLs have been used. All required data structures (like Vectors and Maps) have been implemented from scratch with whatever functionality was required by the application. As a result they may not be complete copies of the original STL implementation.

## Individual contribution
This project was done individually.

## List of known bugs
There are no clear bugs I could recognise as testing performed was limited, however there are limitations to how much the current implementation can achieve in terms of functionality one of the main ones being data persistence across sessions as the focus was towards generic programming concepts.
