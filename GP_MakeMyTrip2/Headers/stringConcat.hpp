#ifndef __STRING_CONCAT_HPP__
#define __STRING_CONCAT_HPP__

#include <sstream>
#include <string>

template<typename... Args>
std::string concat(Args&& ... args)
{   
    std::ostringstream stream;
    ((stream << args << ' '), ...);
    return stream.str();
}

#endif