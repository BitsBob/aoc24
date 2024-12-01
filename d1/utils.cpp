#include <fstream>
#include <iostream>
#include <vector>
#include <string>

#include "utils.h"

int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int lcm(int a, int b) {
    return (a * b) / gcd(a, b);
}

std::vector<std::string> read_from_file(const std::string &filename, int &num_lines) {
    std::ifstream file(filename);
    std::vector<std::string> lines;
    std::string line;

    if (!file.is_open()) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return {};
    }

    while (std::getline(file, line)) {
        lines.push_back(line);
        num_lines++;
    }

    file.close();
    return lines;
}

std::vector<std::string> split(const std::string& s, const std::string& delimiter) {
    std::vector<std::string> tokens;
    size_t pos = 0;
    size_t delimiter_len = delimiter.length();

    while (pos != std::string::npos) {
        size_t found_pos = s.find(delimiter, pos);

        if (found_pos == std::string::npos) {
            tokens.push_back(s.substr(pos));
            break;
        } else {
            tokens.push_back(s.substr(pos, found_pos - pos));
            pos = found_pos + delimiter_len;
        }
    }

    return tokens;
}

