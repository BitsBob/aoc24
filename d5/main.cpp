#include <utility>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <string>

#include "../utils/utils.h"

std::unordered_map<int, std::vector<int>> parse_rules(const std::vector<std::string>& rlines) {
    std::unordered_map<int, std::vector<int>> graph;
    for (const auto& line : rlines) {
        auto parts = split(line, "|");
        int from = std::stoi(parts[0]);
        int to = std::stoi(parts[1]);
        graph[from].push_back(to);
    }
    return graph;
}

bool is_valid_order(const std::vector<int>& update, const std::unordered_map<int, std::vector<int>>& graph) {
    std::unordered_map<int, int> positions;
    for (size_t i = 0; i < update.size(); ++i) {
        positions[update[i]] = i;
    }

    for (const auto& [from, to_list] : graph) {
        for (int to : to_list) {
            if (positions.count(from) && positions.count(to)) {
                if (positions[from] > positions[to]) {
                    return false;
                }
            }
        }
    }
    return true;
}

int partOne() {
    int nlines = 0;
    const std::string f1 = "/home/Audey/aoc24/d5/input1.txt";
    const std::string f2 = "/home/Audey/aoc24/d5/input2.txt";

    std::vector<std::string> rlines = read_from_file(f1, nlines);
    std::vector<std::string> ulines = read_from_file(f2, nlines);

    auto graph = parse_rules(rlines);

    std::vector<std::vector<int>> updates;
    for (const auto& update : ulines) {
        std::vector<int> pages;
        auto parts = split(update, ",");
        for (const auto& part : parts) {
            pages.push_back(std::stoi(part));
        }
        updates.push_back(pages);
    }

    int total = 0;
    for (const auto& update : updates) {
        if (is_valid_order(update, graph)) {
            int middle = update[update.size() / 2];
            total += middle;
        }
    }

    std::cout << "Total: " << total << std::endl;

    return 0;
}

int partTwo() {
    return 0;
}

int main() {
    partOne();
    partTwo();
    return 0;
}