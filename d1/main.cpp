#include <stdio.h>
#include <fstream>
#include <iostream>
#include <vector>
#include <ranges>
#include <string>
#include <algorithm>

#include "utils.h"

int part_one() {
    int num_lines = 0;
    const std::string filename = "/home/Audey/aoc24/d1/input.txt";

    std::vector<std::string> lines = read_from_file(filename, num_lines);
    if (lines.empty()) {
        std::cerr << "Error reading file: " << filename << std::endl;
        return -1;
    }

    std::vector<int> lhs;
    std::vector<int> rhs;
    for (const auto &line : lines) {
        std::vector<std::string> tokens = split(line, "   ");
        lhs.push_back(std::stoi(tokens[0]));
        rhs.push_back(std::stoi(tokens[1]));
    }

    std::sort(lhs.begin(), lhs.end());
    std::sort(rhs.begin(), rhs.end());

    int total = 0;
    for (int i = 0; i < lhs.size(); i++) {
        total += abs(lhs[i] - rhs[i]);
    }
    std::cout << total << std::endl;

    return 0;
}

int part_two() {
    int num_lines = 0;
    const std::string filename = "/home/Audey/aoc24/d1/input.txt";

    std::vector<std::string> lines = read_from_file(filename, num_lines);
    if (lines.empty()) {
        std::cerr << "Error reading file: " << filename << std::endl;
        return -1;
    }

    std::vector<int> lhs;
    std::vector<int> rhs;
    for (const auto &line : lines) {
        std::vector<std::string> tokens = split(line, "   ");
        lhs.push_back(std::stoi(tokens[0]));
        rhs.push_back(std::stoi(tokens[1]));
    }

    std::sort(lhs.begin(), lhs.end());
    std::sort(rhs.begin(), rhs.end());

    int total = 0;
    for (int i = 0; i < lhs.size(); i++) {
        int occ = std::count(rhs.begin(), rhs.end(), lhs[i]);
        total += occ * lhs[i];
    }

    std::cout << total << std::endl;

    return 0;
}

int main() {
    part_one();
    part_two();
    return 0;
}