//
// Created by saahi on 6/24/2024.
//

#ifndef COMMANDLINETOOL_STATS_H
#define COMMANDLINETOOL_STATS_H
#include "dependencies.h"
class Stats{
public:
    static int uniqueWordCount(const std::string &fileName);
    static double averageWordLength(const std::string& filename);
    static int specificCharacterCount(const std::string& filename, char specificChar);
};
#endif //COMMANDLINETOOL_STATS_H
