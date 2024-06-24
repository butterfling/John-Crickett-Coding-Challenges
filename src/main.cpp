#include "../include/dependencies.h"
#include "../include/error.h"
#include "../include/count.h"
#include "../include/stats.h"

//TODO:
//1) Support basic functionalities:
//  a-> word count, line count, bytes, charecter count
// find
void printUsage() {
    std::cout << "Usage: cwctool -l <filename>  (line count)\n";
    std::cout << "       cwctool -w <filename>  (word count)\n";
    std::cout << "       cwctool -c <filename>  (character count)\n";
    std::cout << "       cwctool -b <filename>  (byte count)\n";
    std::cout << "       cwctool -uw <filename> (unique word count)\n";
    std::cout << "       cwctool -aw <filename> (average word length)\n";
    std::cout << "       cwctool -sc <filename> <char> (specific character count)\n";
}

int main(int argc, char* argv[]) {
    if (argc < 3) {
        printUsage();
        return 1;
    }
    std::string flag = argv[1];
    std::string filename = argv[2];
    char specificChar = argc == 4 ? argv[3][0] : '\0';

    std::unordered_map<std::string, std::function<int(const std::string&)>> handlers = {
            {"-l", Count::countLines},
            {"-w", Count::countWords},
            {"-c", Count::countCharecters},
            {"-b", Count::countBytes},
            {"-uw", Stats::uniqueWordCount},
            {"-aw", [filename](const std::string&) -> int {
                double avgLength = Stats::averageWordLength(filename);
                if (avgLength >= 0) {
                    std::cout << "Average word length: " << avgLength << "\n";
                    return 0;
                }
                return -1;
            }}
    };

    try {
        if (flag == "-sc" && specificChar != '\0') {
            int result = Stats::specificCharacterCount(filename, specificChar);
            if (result >= 0) {
                std::cout << "Number of '" << specificChar << "' characters: " << result << "\n";
            }
        } else {
            auto it = handlers.find(flag);
            if (it != handlers.end()) {
                int result = it->second(filename);
                if (result >= 0) {
                    if (flag == "-l") {
                        std::cout << "Number of lines: " << result << "\n";
                    } else if (flag == "-w") {
                        std::cout << "Number of words: " << result << "\n";
                    } else if (flag == "-c") {
                        std::cout << "Number of characters: " << result << "\n";
                    } else if (flag == "-b") {
                        std::cout << "Number of bytes: " << result << "\n";
                    }
                    else if (flag == "-uw") {
                        std::cout << "Number of unique words: " << result << "\n";
                    }
                }
            } else {
                printUsage();
                return 1;
            }
        }
    } catch (const FileError& e) {
        std::cerr << e.what() << std::endl;
        return 1;
    } catch (const ArgumentError& e) {
        std::cerr << e.what() << std::endl;
        return 1;
    } catch (const std::exception& e) {
        std::cerr << "An unexpected error occurred: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}