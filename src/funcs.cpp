//
// Created by comme on 4/2/2023.
//
#include<string>
#include<vector>
#include<algorithm>

void UpdateIfGreater(int a, int& b){
    if(a > b){
        b = a;
    }
}

void MoveStrings(std::vector<std::string>& source, std::vector<std::string>& destination){
    for(const auto & i : source){
        destination.push_back(i);
    }
    source.clear();
}

void Reverse(std::vector<int>& v){
    std::reverse(v.begin(), v.end());
}

std::vector<int> Reversed(const std::vector<int>& v){
    std::vector<int>copied_vector(v.begin(), v.end());
    std::reverse(copied_vector.begin(), copied_vector.end());
    return copied_vector;
}