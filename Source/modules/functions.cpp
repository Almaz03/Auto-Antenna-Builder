#include <string>
#include "../functions.h"

// Removes double spaces in a line
std::string enters(std::string line) {
    for (int i = 0; i < line.size(); i++) {
        if (i == 0 and line[i] == ' ') {
            line = line.erase(i, 1);
        }
        if (i == line.size() - 1 and line[i] == ' ') {
            line = line.erase(i, 1);
        }
        if (line[i] == ' ' and line[i + 1] == ' ') {
            line = line.erase(i, 1);
        }
    }
    return line;
}

// Convert all characters in the input string to uppercase
std::string fromlowtouppercase(std::string line) {
    for (int i = 0; i < line.size(); i++) {
        if (islower(line[i])) line[i] = toupper(line[i]);
    }
    return line;
}

// Convert the first character of the input string to uppercase and the rest to lowercase
std::string firsttouppercase(std::string line) {
    line[0] = toupper(line[0]);
    for (int i = 1; i < line.size(); i++) {
        line[i] = tolower(line[i]);
    }
    return line;
}