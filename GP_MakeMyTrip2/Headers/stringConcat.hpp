#ifndef __STRING_CONCAT_HPP__
#define __STRING_CONCAT_HPP__

#include <sstream>
#include <string>

//An implementation of a string concatenation method that utilises fold expression
template<typename... Args>
std::string concat(Args&& ... args)
{   
    std::ostringstream stream;
    ((stream << args << ' '), ...);
    return stream.str();
}

#endif