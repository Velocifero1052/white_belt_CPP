//
// Created by comme on 4/2/2023.
//
#include<string>
#include<vector>

bool IsPalindrom(std::string word){
    for(int i = 0; i < word.length() / 2; i++){
        if(word[i] != word[word.length() - 1 - i])
            return false;
    }
    return true;
}

std::vector<std::string> PalindromFilter(std::vector<std::string> words, int minLength){
    std::vector<std::string>res;
    for(auto word: words){
        if(word.length() >= minLength && IsPalindrom(word)){
            res.push_back(word);
        }
    }
    return res;
}