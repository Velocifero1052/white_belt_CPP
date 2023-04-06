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

void print_tasks(const std::vector<std::string>& tasks){
    std::cout << tasks.size();
    for(const auto & task : tasks){
        std::cout << " " << task;
    }
    std::cout << std::endl;
}

void task_manager(){
    int number_of_month = 12;
    int current_position = 0;
    std::vector<std::vector<std::string>> tasks(31);
    std::vector<int> days_count(number_of_month);
    days_count[0] = 30;
    days_count[1] = 27;
    days_count[2] = 30;
    days_count[3] = 29;
    days_count[4] = 30;
    days_count[5] = 29;
    days_count[6] = 30;
    days_count[7] = 30;
    days_count[8] = 29;
    days_count[9] = 30;
    days_count[10] = 29;
    days_count[11] = 30;

    int command_count;
    std::cin >> command_count;

    for(int command_number = 0; command_number < command_count; command_number++){
        std::string command;

        std::cin >> command;
        if(command == "ADD"){
            int day;
            std::string task;
            std::cin >> day >> task;
            tasks[day - 1].push_back(task);
        }else if(command == "DUMP"){
            int day;
            std::cin >> day;
            print_tasks(tasks[day - 1]);
        }else if(command == "NEXT"){
            int prev_position = current_position;
            if(current_position == number_of_month - 1)
                current_position = 0;
            else
                current_position++;
            int prev_last_day = days_count[prev_position];
            int current_last_day = days_count[current_position];
            if(current_last_day < prev_last_day){
                for(int i = current_last_day + 1; i <= prev_last_day; i++){
                    tasks[current_last_day].insert(tasks[current_last_day].end(),
                                                   tasks[i].begin(),
                                                   tasks[i].end());
                    tasks[i].clear();
                }
            }
        }
    }
}

void anagram_check(){
    int count;
    std::cin >> count;
    for(int i = 0; i < count; i++){
        std::string first, second;
        std::cin >> first >> second;
        sort(first.begin(), first.end());
        sort(second.begin(), second.end());
        if(first == second)
            std::cout << "YES" << std::endl;
        else
            std::cout << "NO" << std::endl;
    }
}

#endif //WHITE_BELT_CPP_SOLUTIONS_H
