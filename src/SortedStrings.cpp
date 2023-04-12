//
// Created by Legion on 4/12/2023.
//
#include <string>
#include <vector>
#include <algorithm>

class SortedStrings {
public:
    void AddString(const std::string& s) {
        strings.push_back(s);
        sort(strings.begin(), strings.end());
    }
    std::vector<std::string> GetSortedStrings() {
        return strings;
    }
private:
    std::vector<std::string>strings;
};
