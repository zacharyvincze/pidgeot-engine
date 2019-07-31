#pragma once

#include <map>
#include <string>

namespace Pidgeot {
class Config {
public:
    Config(const std::string filepath);
    std::string getOption(const std::string option);
    int getNumOption(const std::string option);
    bool getBoolOption(const std::string option);

private:
    std::map<std::string, std::string> m_options;
};
}