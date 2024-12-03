#ifndef UTILS_H
#define UTILS_H

#include <string>
#include <vector>

#define LOG(x) std::cout << "[LOG] " << x << std::endl;
#define ERROR_LOG(x) std::cerr << "[ERROR] " << x << std::endl;

#define ASSERT(condition, msg) \
if (!(condition)) { \
std::cerr << "[ASSERT] " << msg << std::endl; \
std::abort(); \
}

int gcd(int a, int b);
int lcm(int a, int b);

std::vector<std::string> read_from_file(const std::string &filename, int &num_lines);
std::vector<std::string> split(const std::string& s, const std::string& delimiter);
std::vector<int> stringToIntVector(const std::string& str);

#endif // UTILS_H
