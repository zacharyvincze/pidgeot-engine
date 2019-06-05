#include "modules/config.h"

#include <fstream>
#include <iostream>
#include <algorithm>
#include <stdexcept>

#include "log.h"
#include "utils/string-utils.h"

Config::Config(const std::string filepath) {
    ENGINE_DEBUG("Initializing configuration module");
    std::ifstream configuration_file;
    configuration_file.open(filepath.c_str());
    if (!configuration_file.is_open()) {
        ENGINE_ERROR("Unable to read configuration file: {}", filepath.c_str());
        exit(-1);
    }

    // Read configuration file line by line
    while (!configuration_file.eof()) {
        std::string input;
        getline(configuration_file, input);
        std::string delimeter = ":";

        std::string token = input.substr(0, input.find(delimeter));
        std::transform(token.begin(), token.end(), token.begin(), ::tolower);
        token = stringutils::trim(token);
        std::string option = input.erase(0, input.find(delimeter)+1);
        std::transform(option.begin(), option.end(), option.begin(), ::tolower);
        option = stringutils::trim(option);

        m_options.insert(std::pair<std::string, std::string>(token, option));
        spdlog::debug("{}: {}", token.c_str(), option.c_str());
    }
}

std::string Config::getOption(const std::string option) {
    try {
        return m_options.at(option);
    } catch (std::out_of_range& e) {
        ENGINE_ERROR("Error when processing option {}: {}\n", option.c_str(), e.what());
    }
}

int Config::getNumOption(const std::string option) {
    try {
        return stoi(getOption(option));
    } catch (std::exception &e) {
        ENGINE_ERROR("Error when converting option {} to numerical value: {}", option.c_str(), e.what());
    }
}

bool Config::getBoolOption(const std::string option) {
    return (getOption(option) == "true");
}