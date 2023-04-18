//
// Created by Legion on 3/31/2023.
//

#ifndef WHITE_BELT_CPP_SOLUTIONS_H
#define WHITE_BELT_CPP_SOLUTIONS_H

#include <iostream>
#include <cmath>
#include <bitset>
#include <vector>
#include <map>
#include <set>
#include <numeric>
#include <algorithm>
#include <iomanip>
#include <fstream>

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

void capitals_and_countries(){
    std::map<std::string, std::string>capitals;
    int command_count;
    std::cin >> command_count;

    for(int i = 0; i < command_count; i++){
        std::string command;
        std::cin >> command;
        if(command == "CHANGE_CAPITAL"){
            std::string country, new_capital;
            std::cin >> country >> new_capital;
            if(capitals.count(country) == 0){
                std::cout << "Introduce new country " << country << " with capital " << new_capital << std::endl;
                capitals[country] = new_capital;
            }else if(capitals[country] == new_capital){
                std::cout << "Country " << country << " hasn't changed its capital" << std::endl;
            }else{
                std::cout << "Country " << country << " has changed its capital from " << capitals[country] << " to " << new_capital << std::endl;
                capitals[country] = new_capital;
            }
        }else if(command == "RENAME"){
            std::string old_country_name, new_country_name;
            std::cin >> old_country_name >> new_country_name;
            if(old_country_name == new_country_name || capitals.count(old_country_name) == 0 || capitals.count(new_country_name) == 1){
                std::cout << "Incorrect rename, skip" << std::endl;
            }else{
                std::string capital = capitals[old_country_name];
                std::cout << "Country " << old_country_name << " with capital " << capital << " has been renamed to " << new_country_name << std::endl;
                capitals.erase(old_country_name);
                capitals[new_country_name] = capital;
            }
        }else if(command == "ABOUT"){
            std::string country;
            std::cin >> country;
            if(capitals.count(country) == 0){
                std::cout << "Country " << country << " doesn't exist" << std::endl;
            }else{
                std::cout << "Country " << country << " has capital " << capitals[country] << std::endl;
            }
        }else if(command == "DUMP"){
            if(capitals.empty()){
                std::cout << "There are no countries in the world" << std::endl;
            }else{
                bool first = true;
                for(const auto& [key, value]: capitals){
                    if(first){
                        std::cout << key << "/" << value;
                        first = false;
                    }else{
                        std::cout << " " << key << "/" << value;
                    }
                }
                std::cout << std::endl;
            }
        }
    }
}

void print_vector(const std::vector<std::string>& vector, std::string to_exclude, bool exclusion){
    bool first = true;
    for(const std::string& s : vector){
        if(exclusion){
            if(s == to_exclude){
                continue;
            }
        }
        if (first){
            first = false;
            std::cout << s;
        }else{
            std::cout << " " << s;
        }
    }
    std::cout << std::endl;
}

void bus_stops_one(){
    std::map<std::string, std::vector<std::string>> stops_to_buses;
    std::map<std::string, std::vector<std::string>> buses_to_stops;
    int command_count;
    std::cin >> command_count;

    for (int i = 0; i < command_count; i++){
        std::string command;
        std::cin >> command;
        if(command == "NEW_BUS"){
            //NEW_BUS bus stop_count stop1 stop2 ...
            std::string bus;
            int stop_count;
            std::cin >> bus >> stop_count;
            for(int j = 0; j < stop_count; j++){
                std::string stop;
                std::cin >> stop;
                if(stops_to_buses.count(stop) == 0){
                    stops_to_buses[stop] = {};
                }
                if(buses_to_stops.count(bus) == 0){
                    buses_to_stops[bus] = {};
                }
                stops_to_buses[stop].push_back(bus);
                buses_to_stops[bus].push_back(stop);
            }
        } else if(command == "BUSES_FOR_STOP"){
            std::string stop;
            std::cin >> stop;
            if(stops_to_buses.count(stop) == 0){
                std::cout << "No stop" << std::endl;
            }else{
                print_vector(stops_to_buses[stop], "", false);
            }
        } else if(command == "STOPS_FOR_BUS"){
            std::string bus;
            std::cin >> bus;
            if(buses_to_stops.count(bus) == 0){
                std::cout << "No bus" << std::endl;
            }else{
                for(const auto& stop: buses_to_stops[bus]){
                    std::cout << "Stop " << stop << ": ";
                    if(stops_to_buses[stop].size() == 1){
                        std::cout << "no interchange" << std::endl;
                    }else{
                        print_vector(stops_to_buses[stop], bus, true);
                    }
                }
            }
        } else if(command == "ALL_BUSES"){
            if(buses_to_stops.empty()){
                std::cout << "No buses" << std::endl;
            }else{
                for(const auto& bus: buses_to_stops){
                    std::cout << "Bus " << bus.first << ": ";
                    print_vector(bus.second, "", false);
                }
            }
        }
    }
}

void bus_stops_two(){
    std::map<std::vector<std::string>, int> directions;
    int command_count;
    std::cin >> command_count;
    int direction_count = 0;
    for(int i = 0; i < command_count; i++){
        int stops_count;
        std::cin >> stops_count;
        std::vector<std::string> stops(stops_count);
        for (int j = 0; j < stops_count; j++){
            std::string stop;
            std::cin >> stop;
            stops.push_back(stop);
        }
        if(directions.count(stops) == 0){
            direction_count++;
            directions[stops] = direction_count;
            std::cout << "New bus " << direction_count << std::endl;
        }else{
            std::cout << "Already exists for " << directions[stops] << std::endl;
        }
    }
}

std::set<std::string> BuildMapValuesSet(const std::map<int, std::string>& m){
    std::set<std::string> res;
    for(const auto & [key, value]: m){
        res.insert(value);
    }
    return res;
}

void synonyms(){

    std::map<std::string, std::set<std::string>> synonyms;

    int n;
    std::cin >> n;

    for (int i = 0; i < n; i++) {
        std::string s;
        std::cin >> s;
        if (s == "ADD"){
            std::string word, synonym;
            std::cin >> word >> synonym;
            synonyms[word].insert(synonym);
            synonyms[synonym].insert(word);
        }else if (s == "COUNT"){
            std::string word;
            std::cin >> word;
            if(synonyms.count(word) == 0){
                std::cout << 0 << std::endl;
            }else{
                std::cout << synonyms[word].size() << std::endl;
            }
        }else if(s == "CHECK"){
            std::string word, synonym;
            std::cin >> word >> synonym;
            if(synonyms.count(word) == 0){
                std::cout << "NO" << std::endl;
            }else{
                if(synonyms[word].count(synonym) == 0){
                    std::cout << "NO" << std::endl;
                }else{
                    std::cout << "YES" << std::endl;
                }
            }
        }
    }

}

void bus_stops_three(){
    std::map<std::set<std::string>, int> directions;
    int command_count;
    std::cin >> command_count;
    int direction_count = 0;
    for(int i = 0; i < command_count; i++){
        int stops_count;
        std::cin >> stops_count;
        std::set<std::string> stops;
        for (int j = 0; j < stops_count; j++){
            std::string stop;
            std::cin >> stop;
            stops.insert(stop);
        }
        if(directions.count(stops) == 0){
            direction_count++;
            directions[stops] = direction_count;
            std::cout << "New bus " << direction_count << std::endl;
        }else{
            std::cout << "Already exists for " << directions[stops] << std::endl;
        }
    }
}

void sort_case_insensitive(){
    int n;
    std::cin >> n;
    std::vector<std::string> v(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> v[i];
    }

    sort(v.begin(), v.end(), [](std::string x, std::string y) {
        transform(x.begin(), x.end(), x.begin(),
                  [](unsigned char c){ return std::tolower(c); });
        transform(y.begin(), y.end(), y.begin(),
                  [](unsigned char c){ return std::tolower(c); });
        return x < y;
    });

    bool first = true;
    for (int i = 0; i < n; ++i) {
        if (first) {
            std::cout << v[i];
            first = false;
        }else {
            std::cout << " " << v[i];
        }
    }
}

void print_vector(const std::vector<int>& v){
    bool first = true;
    for(int i : v){
        if(first){
            std::cout << std::setw(10) <<  i;
            first = false;
        }else{
            std::cout << " " << std::setw(10) << i;
        }
    }
}

void ReadAll(const std::string& path){
    int n, m;
    std::ifstream input(path);
    if(input){
        input >> n >> m;
        std::vector<int> line_buf(m);

        for(int i = 0; i < n; i++){
            bool first = true;
            for(int j = 0; j < m; j++){
                if(first){
                    input >> line_buf[j];
                    first = false;
                }else{
                    input.ignore(1);
                    input >> line_buf[j];
                }
            }
            print_vector(line_buf);
            if(i != n - 1)
                std::cout << '\n';
        }

    }
}


struct student{
    std::string name;
    std::string lastname;
    int day{};
    int month{};
    int year{};
};


void students_birth_dates(){
    int number_of_commands;
    std::cin >> number_of_commands;
    std::vector<student> students(number_of_commands);
    std::string name, lastname;
    int day, month, year;
    for(int i = 0; i < number_of_commands; i++){
        std::cin >> name >> lastname >> day >> month >> year;
        students[i] = {name, lastname, day, month, year};
    }
    std::cin >> number_of_commands;

    for(int i = 0; i < number_of_commands; i++){
        std::string command;
        int number;
        std::cin >> command >> number;
        if(number > students.size() || number <= 0) {
            std::cout << "bad request\n";
            continue;
        }
        if(command == "name"){
            std::cout << students[number-1].name << " " << students[number-1].lastname << '\n';
        }else if(command == "date"){
            std::cout << students[number-1].day << "." << students[number-1].month << "." << students[number-1].year << '\n';
        }else{
            std::cout << "bad request\n";
        }
    }
}

#endif //WHITE_BELT_CPP_SOLUTIONS_H
