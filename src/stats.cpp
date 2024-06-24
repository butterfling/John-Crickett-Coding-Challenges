//
// Created by saahi on 6/24/2024.
//
#include "../include/stats.h"
#include "../include/error.h"

int Stats::uniqueWordCount(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        throw FileError(filename);
    }

    std::string word;
    std::unordered_set<std::string> uniqueWords;
    while (file >> word) {
        uniqueWords.insert(word);
    }
    file.close();
    return uniqueWords.size();
}

double Stats::averageWordLength(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        throw FileError(filename);
    }

    std::string word;
    int totalLength = 0;
    int wordCount = 0;
    while (file >> word) {
        totalLength += word.length();
        wordCount++;
    }
    file.close();
    return wordCount > 0 ? static_cast<double>(totalLength) / wordCount : 0.0;
}

int Stats::specificCharacterCount(const std::string& filename, char specificChar) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        throw FileError(filename);
    }
    char ch;
    int charCount = 0;
    while (file.get(ch)) {
        if (ch == specificChar) {
            charCount++;
        }
    }
    file.close();
    return charCount;
}
