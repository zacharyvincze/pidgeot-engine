#include "modules/config.h"

#include <fstream>
#include <iostream>
#include <algorithm>
#include <stdexcept>

Config::Config(const std::string filepath) {
    std::ifstream configuration_file;
    configuration_file.open(filepath.c_str());
    if (!configuration_file.is_open()) {
        printf("Could not read configuration file: %s\n", filepath.c_str());
        exit(-1);
    }

    // Read configuration file line by line
    while (!configuration_file.eof()) {
        std::string input;
        getline(configuration_file, input);
        std::string delimeter = ":";

        std::string token = input.substr(0, input.find(delimeter));
        std::transform(token.begin(), token.end(), token.begin(), ::tolower);
        std::string option = input.erase(0, input.find(delimeter)+1);
        std::transform(option.begin(), option.end(), option.begin(), ::tolower);

        m_options.insert(std::pair<std::string, std::string>(token, option));
        printf("CONFIG: %s: %s\n", token.c_str(), option.c_str());
    }
}

std::string Config::getOption(const std::string option) {
    try {
        return m_options.at(option);
    } catch (std::out_of_range& e) {
        printf("Error when processing option %s: %s\n", option.c_str(), e.what());
    }
}

int Config::getNumOption(const std::string option) {
    try {
        return stoi(getOption(option));
    } catch (std::exception &e) {
        printf("Error when converting option %s to numerical value: %s", option.c_str(), e.what());
    }
}

bool Config::getBoolOption(const std::string option) {
    return (getOption(option) == "true");
}