//
// Created by saahi on 6/24/2024.
//
#include "../include/count.h"
#include "../include/dependencies.h"

int Count::countWords(const std::string &fileName) {
    std::ifstream file(fileName);
    if(!file.is_open()){
        throw FileError(fileName);
    }
    std::string word;
    int wordCount=0;
    while(file>>word){
        wordCount++;
    }
    file.close();
    return wordCount;
}


int Count::countLines(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        throw FileError(filename);
    }
    std::string line;
    int lineCount = 0;
    while (std::getline(file, line)) {
        ++lineCount;
    }
    file.close();
    return lineCount;
}

int Count::countCharecters(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        throw FileError(filename);
    }

    char ch;
    int charCount = 0;
    while (file.get(ch)) {
        charCount++;
    }
    file.close();
    return charCount;
}

int Count::countBytes(const std::string& filename) {
    std::ifstream file(filename, std::ios::binary | std::ios::ate);
    if (!file.is_open()) {
        throw FileError(filename);
    }
    int byteCount = file.tellg();
    file.close();
    return byteCount;
}