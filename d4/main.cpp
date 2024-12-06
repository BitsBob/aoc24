#include <string>
#include <vector>
#include <iostream>
#include <bits/stdc++.h>

#include "../utils/utils.h"

bool search_direction(const std::vector<std::string> &grid, int row, int col, int drow, int dcol, std::string target) {
    int rows = grid.size();
    int cols = grid[0].size();

    for (int i = 0; i < target.size(); i++) {
        int newRow = row + i * drow;
        int newCol = col + i * dcol;

        if (newRow < 0 || newRow >= rows || newCol < 0 || newCol >= cols || grid[newRow][newCol] != target[i]) {
            return false;
        }
    }
    return true;
}

bool check_diagonals(const std::vector<std::string> &grid, int r, int c) {

    std::string first_diag = {grid[r][c], grid[r + 1][c + 1], grid[r + 2][c + 2]};
    std::string second_diag = {grid[r][c + 2], grid[r + 1][c + 1], grid[r + 2][c]};

    const std::string valid_string1 = "MAS";
    const std::string valid_string2 = "SAM";

    if ((first_diag == valid_string1 || first_diag == valid_string2) &&
        (second_diag == valid_string1 || second_diag == valid_string2)) {
        return true;
    }

    return false;
}


int part_one() {
    int count = 0;

    int num_lines = 0;
    const std::string filename = "/home/Audey/aoc24/d4/input.txt";
    std::vector<std::string> lines = read_from_file(filename,num_lines);

    int rows = lines.size();
    int cols = lines[0].size();

    std::vector<std::pair<int, int>> directions = {
        {0, 1},  {0, -1},  // Horizontal
        {1, 0},  {-1, 0},  // Vertical
        {1, 1},  {1, -1},  // Diagonal
        {-1, 1}, {-1, -1}  // Diagonal
    };

    for (int row = 0; row < rows; row++) {
        for (int col = 0; col < cols; col++) {
            for (auto [dRow, dCol] : directions) {
                if (search_direction(lines, row, col, dRow, dCol, "XMAS")) {
                    count++;
                }
            }
        }
    }

    std::cout << count << std::endl;

    return 0;
}

int part_two() {
    int count = 0;

    int num_lines = 0;
    const std::string filename = "/home/Audey/aoc24/d4/input.txt";
    std::vector<std::string> lines = read_from_file(filename,num_lines);

    int rows = lines.size();
    int cols = lines[0].size();

    std::vector<std::pair<int, int>> directions = {
        {1, 1},  {1, -1},  // Diagonal
        {-1, 1}, {-1, -1}  // Diagonal
    };

    for (int row = 0; row < rows - 2; row++) {
        for (int col = 0; col < cols - 2; col++) {
            if (check_diagonals(lines, row, col)) {
                ++count;
            }
        }
    }
    
    std::cout << count << std::endl;
    
    return 0;
}

int main() {
    part_one();
    part_two();
    return 0;
}