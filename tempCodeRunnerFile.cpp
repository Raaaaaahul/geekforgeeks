#include <iostream>
#include <vector>
#include <string>
#include <cmath>

std::vector<std::string> compareStrings(std::vector<std::string> vec1, std::vector<std::string> vec2) {
    std::vector<std::string> result;
    for (int i = 0; i < vec1.size(); i++) {
        std::string res = "YES";
        for (int j = 0; j < vec1[i].size(); j++) {
            if (std::abs(vec1[i][j] - vec2[i][j]) > 3) {
                res = "NO";
                break;
            }
        }
        result.push_back(res);
    }
    return result;
}

int main() {
    std::vector<std::string> vec1 = {"aaaaab"};
    std::vector<std::string> vec2 = {"k"};
    std::vector<std::string> result = compareStrings(vec1, vec2);
    for (const auto &str : result) {
        std::cout << str << std::endl;
    }
    return 0;
}
