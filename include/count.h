//
// Created by saahi on 6/24/2024.
//
#ifndef COMMANDLINETOOL_COUNT_H
#define COMMANDLINETOOL_COUNT_H
#include "dependencies.h"
#include "error.h"
class Count {
public:
    static int countWords(const std::string &fileName);
    static int countLines(const std::string &fileName);
    static int countCharecters(const std::string&fileName);
    static int countBytes(const std::string&fileName);
};
#endif //COMMANDLINETOOL_COUNT_H
