#pragma once

#include <string>

namespace stringutils {

const std::string WHITESPACE = " \n\r\t\f\v";

extern std::string ltrim(const std::string& input)
{
    size_t start = input.find_first_not_of(WHITESPACE);
    return (start == std::string::npos) ? "" : input.substr(start);
}

extern std::string rtrim(const std::string& input)
{
    size_t end = input.find_last_not_of(WHITESPACE);
    return (end == std::string::npos) ? "" : input.substr(0, end + 1);
}

extern std::string trim(const std::string& input)
{
    return rtrim(ltrim(input));
}
}