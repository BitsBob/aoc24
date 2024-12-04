#include <iostream>
#include <string>
#include <vector>
#include <regex>

#include "../utils/utils.h"

int part_one() {
    int num_lines = 0;
    const std::string filename = "/home/Audey/aoc24/d3/input.txt";
    std::vector<std::string> lines = read_from_file(filename,num_lines);

    std::string inp = lines[0];
    std::regex pattern(R"(mul\((\d+),(\d+)\))");
    std::smatch matches;
    std::vector<std::pair<int, int>> results;

    for (const auto& line : lines) {
        std::string::const_iterator search_start(line.cbegin());
        while (std::regex_search(search_start, line.cend(), matches, pattern)) {
            int num1 = std::stoi(matches[1].str());
            int num2 = std::stoi(matches[2].str());
            results.push_back({num1, num2});
            search_start = matches.suffix().first;
        }
    }

    int sum = 0;
    for (auto &pair : results) {
        sum += pair.first * pair.second;
    }

    std::cout << sum << std::endl;

    return 0;
}

int part_two() {
    const std::string filename = "/home/Audey/aoc24/d3/input.txt";
    int total_count = 0;
    bool is_enabled = true;
    int num_lines = 0;
    std::vector<std::string> lines = read_from_file(filename, num_lines);
    std::regex mul_pattern(R"(^mul\((\d+),(\d+)\))");

    for (const auto& line : lines) {
        size_t index = 0;

        while (index < line.size()) {
            if (line.compare(index, 7, "don't()") == 0) {
                is_enabled = false;
                index += 7;
            } else if (line.compare(index, 4, "do()") == 0) {
                is_enabled = true;
                index += 4;
            } else if (line.compare(index, 4, "mul(") == 0) {
                if (is_enabled) {
                    std::smatch match;
                    std::string remaining = line.substr(index);
                    if (std::regex_search(remaining, match, mul_pattern)) {
                        int value1 = std::stoi(match[1]);
                        int value2 = std::stoi(match[2]);
                        total_count += value1 * value2;
                        index += match[0].length();
                    } else {
                        ++index;
                    }
                } else {
                    index += 4;
                }
            } else {
                ++index;
            }
        }
    }

    std::cout << total_count << std::endl;
    return 0;
}


int main() {
    part_one();
    part_two();
    return 0;
}