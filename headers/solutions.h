//
// Created by Legion on 3/31/2023.
//

#ifndef WHITE_BELT_CPP_SOLUTIONS_H
#define WHITE_BELT_CPP_SOLUTIONS_H

#include <iostream>
#include <cmath>

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

#endif //WHITE_BELT_CPP_SOLUTIONS_H
