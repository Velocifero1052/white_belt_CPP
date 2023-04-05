//
// Created by Legion on 3/31/2023.
//

#ifndef WHITE_BELT_CPP_SOLUTIONS_H
#define WHITE_BELT_CPP_SOLUTIONS_H

#include <iostream>
#include <cmath>
#include <bitset>
#include <vector>
#include <numeric>
#include <algorithm>

void square_equation_solution(){
    double a, b, c;
    std::cin >> a >> b >> c;
    if(a != 0.0 && b != 0.0) {
        double under_root_expression = b * b - 4 * a * c;
        if (under_root_expression < 0.0) {
            return;
        } else if (under_root_expression == 0.0) {
            std::cout << -b / (2 * a);
        } else {
            under_root_expression = sqrt(under_root_expression);
            double x1 = (-b + under_root_expression) / (2 * a);
            double x2 = (-b - under_root_expression) / (2 * a);
            std::cout << x1 << " " << x2;
        }
    }else if(a == 0.0 && b != 0.0 && c != 0.0){
        std::cout << - c / b;
    }else if(a != 0.0 && b == 0.0 && c == 0.0 || a == 0.0 && b != 0.0 && c == 0.0){
        std::cout << 0.0;
    }else if(a != 0.0 && b == 0.0 && c != 0.0 && -c / a >= 0.0){
        auto res = sqrt (-c/a);
        std::cout << res << " " << -res;
    }
}

void so_called_impossible_func(){
    int a, b;
    std::cin >> a >> b;
    if(b != 0){
        std::cout << a / b;
    }else{
        std::cout << "Impossible";
    }
}

void price_calculations(){
    double n, a, b, x, y, final_price;
    std::cin >> n >> a >> b >> x >> y;
    final_price = n;
    if(n > a && n > b)
        final_price = n - n * (y / 100.0);
    else if(n > a && n <= b)
        final_price = n - n * (x / 100.0);

    std::cout << final_price;
}

void print_even_numbers(){
    int x, y, i;
    bool first = true;
    std::cin >> x >> y;

    if (x == y && x % 2 == 0){
        std::cout << x;
        return;
    }else if(x % 2 == 0){
        i = x;
    }else{
        i = x + 1;
    }

    for(; i <= y; i += 2){
        if(first){
            std::cout << i;
            first = false;
        }else{
            std::cout << " " << i;
        }
    }
}

void second_occurrence_of_f(){
    std::string word;
    std::cin >> word;
    int found_index = -2;
    auto first = true;
    for(auto i = 0; i < word.length(); i++){
        if(word[i] == 'f' && first) {
            found_index = -1;
            first = false;
        }else if(word[i] == 'f' && !first){
            found_index = i;
            break;
        }
    }
    std::cout << found_index;
}

int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

void convert_to_binary_string(){
    int n;
    std::cin >> n;
    std::string res = std::bitset<32>(n).to_string();
    std::cout << std::string(res.begin() + res.find('1'), res.end());
}

void lower_than_average(){
    int size_of_vector;
    std::cin >> size_of_vector;
    std::vector<int> temps(size_of_vector);

    for(int i = 0; i < size_of_vector; i++){
        int temp;
        std::cin >> temp;
        temps[i] = temp;
    }

    int common_value = std::accumulate(temps.begin(), temps.end(), 0) / temps.size();
    std::vector<int>higher_that_average;

    for(int i = 0; i < size_of_vector; i++){
        if(temps[i] > common_value)
            higher_that_average.push_back(i);
    }


    std::cout << higher_that_average.size() << std::endl;
    bool first = true;
    for(auto elem: higher_that_average){
        if(first){
            std::cout << elem;
            first = false;
        }else{
            std::cout << " " << elem;
        }
    }
}

void worry_count(){
    std::vector<int> people;

    int number_of_commands;
    std::cin >> number_of_commands;
    int default_value = 1;
    int worry_value = -1;
    std::string command;
    for(int i = 0; i < number_of_commands; i++){
        std::cin >> command;
        if (command == "WORRY") {
            int index;
            std::cin >> index;
            people[index] = worry_value;
        }
        else if (command == "QUIET") {
            int index;
            std::cin >> index;
            people[index] = default_value;
        }
        else if (command == "COME") {
            int number;
            std::cin >> number;
            if(number > 0){
                for(int j = 0; j < number; j++){
                    people.push_back(default_value);
                }
            }else if(number < 0){
                number = -number;
                for(int j = 0; j < number; j++){
                    people.pop_back();
                }
            }
        }
        else if (command == "WORRY_COUNT") {
            std::cout << std::count(people.begin(), people.end(), worry_value) << std::endl;
        }
    }
}

#endif //WHITE_BELT_CPP_SOLUTIONS_H
