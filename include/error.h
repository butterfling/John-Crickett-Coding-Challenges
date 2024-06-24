//
// Created by saahi on 6/24/2024.
//

#ifndef COMMANDLINETOOL_ERROR_H
#define COMMANDLINETOOL_ERROR_H
#include "dependencies.h"
class FileError : public std::exception{
private:
    std::string message;
public:
    explicit FileError(const std::string &fileName) :
        message("Error: Could not open file "+fileName){}

    [[nodiscard]] const char *what() const noexcept override{
        return message.c_str();
    }
};

class ArgumentError : public std::exception{
private:
    std::string message;
public:
    explicit ArgumentError(const std::string& msg)
            : message("Argument Error: " + msg) {}

    [[nodiscard]] const char* what() const noexcept override {
        return message.c_str();
    }
};
#endif //COMMANDLINETOOL_ERROR_H
