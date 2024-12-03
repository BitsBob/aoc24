#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <string>

#include "../utils/utils.h"

bool isSafeOne(const std::vector<int>& row) {
    if (row.size() == 1) {
        return true;
    }

    if (!std::is_sorted(row.begin(), row.end()) && 
        !std::is_sorted(row.rbegin(), row.rend())) {
        return false;
    }

    bool isDecreasing = true;
    bool isIncreasing = true;
    
    for (size_t i = 1; i < row.size(); ++i) {
        int diff = std::abs(row[i] - row[i - 1]);
        if (diff < 1 || diff > 3) {
            return false;
        }

        if (row[i] > row[i - 1]) {
            isDecreasing = false;
        }
        if (row[i] < row[i - 1]) {
            isIncreasing = false;
        }
    }

    return isDecreasing || isIncreasing;
}

bool isSafeTwo(const std::vector<int>& row) {
    if (isSafeOne(row)) {
        return true;
    }

    for (int i=0; i<row.size(); ++i) {
        std::vector<int> rrow = row;
        rrow.erase(rrow.begin()+i);
        if (isSafeOne(rrow)) {
            return true;
        }
    }

    return false;
    
}

int part1() {
    int num_lines = 0;
    const std::string filename = "/home/Audey/aoc24/d2/input.txt";
    std::vector<std::string> lines = read_from_file(filename, num_lines);

    int count = 0;
    for (const auto &line : lines) {
        std::vector<int> levels = stringToIntVector(line);

        if (isSafeOne(levels)) {
            ++count;
        }
    }

    std::cout << count << std::endl;
    return 0;
}

int part2() {
    int num_lines = 0;
    const std::string filename = "/home/Audey/aoc24/d2/input.txt";
    std::vector<std::string> lines = read_from_file(filename, num_lines);

    int count = 0;
    for (const auto &line : lines) {
        std::vector<int> levels = stringToIntVector(line);

        if (isSafeTwo(levels)) {
            ++count;
        }
    }

    std::cout << count << std::endl;
    return 0;
}

int main() {
    part1();
    part2();

    return 0;
}