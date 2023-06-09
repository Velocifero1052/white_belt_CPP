//
// Created by Legion on 4/20/2023.
//
#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
#include <set>
#include <sstream>

class Rational {
public:
    Rational() {
        numerator = 0;
        denominator = 1;
    }

    Rational(int numerator_, int denominator_) {
        if(denominator_ == 0)
            throw std::invalid_argument("Invalid argument");
        bool numerator_positive = numerator_ > 0;
        bool denominator_positive = denominator_ > 0;

        int a_num = abs(numerator_);
        int a_den = abs(denominator_);

        shorten_for_common(a_num, a_den);

        numerator = a_num;
        denominator = a_den;

        numerator = numerator_positive ? numerator : -numerator;
        denominator = denominator_positive ? denominator : -denominator;

        if(denominator < 0){
            denominator = -denominator;
            numerator = -numerator;
        }

        if(numerator == 0){
            denominator = 1;
        }

    }

    int Numerator() const {
        return numerator;
    }

    int Denominator() const {
        return denominator;
    }

    Rational operator+(const Rational& rhs){
        if(this->denominator == rhs.denominator) {
            this->numerator += rhs.numerator;
            return {this->numerator, this->denominator};
        }else{
            int common_multiple = lcm(this->denominator, rhs.denominator);
            int left_to_multiply = common_multiple / this->denominator;
            int right_to_multiply = common_multiple / rhs.denominator;
            this->numerator *= left_to_multiply;
            int right_numerator = rhs.numerator * right_to_multiply;
            int res = this->numerator + right_numerator;
            return {res, common_multiple};
        }
    }

    Rational operator-(const Rational& rhs){
        if(this->denominator == rhs.denominator)
            this->numerator -= rhs.numerator;
        else{
            int common_multiple = lcm(this->denominator, rhs.denominator);
            int left_to_multiply = common_multiple / this->denominator;
            int right_to_multiply = common_multiple / rhs.denominator;
            this->numerator *= left_to_multiply;
            int right_numerator = rhs.numerator * right_to_multiply;
            int res = this->numerator - right_numerator;
            return {res, common_multiple};
        }
        return {this->numerator, this->denominator};
    }

    Rational operator*(const Rational& rhs) const{
        return {this->numerator * rhs.numerator, this->denominator * rhs.denominator};
    }

    Rational operator/(const Rational& rhs)const{
        if(rhs.Numerator() == 0){
            throw std::domain_error("Division by zero");
        }
        return {this->numerator * rhs.denominator, this->denominator * rhs.numerator};
    }

    bool operator==(const Rational& rhs) const{
        return this->numerator == rhs.numerator && this->denominator == rhs.denominator;
    }

    friend bool operator<(const Rational& lhs, const Rational&rhr) {
        return(lhs.Numerator()*rhr.Denominator() < rhr.Numerator()*lhs.Denominator());
    }

    friend std::istream& operator>>(std::istream& stream, Rational& r) {
        int prev_numerator = r.numerator;
        int prev_denominator = r.denominator;
        stream >> r.numerator;
        stream.ignore(1);
        stream >> r.denominator;

        if(r.numerator != prev_numerator || r.denominator != prev_denominator) {
            auto new_r = Rational(r.numerator, r.denominator);
            r = new_r;
        }
        return stream;
    }

    friend std::ostream& operator<<(std::ostream& stream, const Rational& r) {
        stream << r.numerator << "/" << r.denominator;
        return stream;
    }

private:
    // Добавьте поля
    int numerator;
    int denominator;

    int gcd(int a, int b) {
        if (b == 0)
            return a;
        return gcd(b, a % b);
    }

    int lcm(int a, int b){
        int temp = gcd(a, b);
        return temp ? (a / temp * b) : 0;
    }

    void shorten_for_common(int& a_num, int& a_den){
        int common_divider = gcd(a_num, a_den);

        if(common_divider != 1){
            while(a_num % common_divider == 0 && a_den % common_divider == 0){
                a_num /= common_divider;
                a_den /= common_divider;
            }
        }
    }



};

int tests(){

    {
        const Rational r(3, 10);
        if (r.Numerator() != 3 || r.Denominator() != 10) {
            std::cout << "Rational(3, 10) != 3/10" << std::endl;
            return 1;
        }
    }

    {
        const Rational r(8, 12);
        if (r.Numerator() != 2 || r.Denominator() != 3) {
            std::cout << "Rational(8, 12) != 2/3" << std::endl;
            return 2;
        }
    }

    {
        const Rational r(-4, 6);
        if (r.Numerator() != -2 || r.Denominator() != 3) {
            std::cout << "Rational(-4, 6) != -2/3" << std::endl;
            return 3;
        }
    }
    {
        const Rational r(4, -6);
        if (r.Numerator() != -2 || r.Denominator() != 3) {
            std::cout << "Rational(4, -6) != -2/3" << std::endl;
            return 3;
        }
    }

    {
        const Rational r(0, 15);
        if (r.Numerator() != 0 || r.Denominator() != 1) {
            std::cout << "Rational(0, 15) != 0/1" << std::endl;
            return 4;
        }
    }

    {
        const Rational r(-2, -4);
        if (r.Numerator() != 1 || r.Denominator() != 2) {
            std::cout << "Rational(-2, -4) != 1/2" << std::endl;
            return 4;
        }
    }

    {
        const Rational defaultConstructed;
        if (defaultConstructed.Numerator() != 0 || defaultConstructed.Denominator() != 1) {
            std::cout << "Rational() != 0/1" << std::endl;
            return 5;
        }
    }

    {
        Rational r1(4, 6);
        Rational r2(2, 3);
        bool equal = r1 == r2;
        if (!equal) {
            std::cout << "4/6 != 2/3" << std::endl;
            return 1;
        }
    }

    {
        Rational a(2, 3);
        Rational b(4, 3);
        Rational c = a + b;
        bool equal = c == Rational(2, 1);
        if (!equal) {
            std::cout << "2/3 + 4/3 != 2" << std::endl;
            return 2;
        }
    }

    {
        Rational a(5, 7);
        Rational b(2, 9);
        Rational c = a - b;
        bool equal = c == Rational(31, 63);
        if (!equal) {
            std::cout << "5/7 - 2/9 != 31/63" << std::endl;
            return 3;
        }
    }

    {
        Rational a(2, 3);
        Rational b(4, 3);
        Rational c = a * b;
        bool equal = c == Rational(8, 9);
        if (!equal) {
            std::cout << "2/3 * 4/3 != 8/9" << std::endl;
            return 1;
        }
    }

    {
        Rational a(5, 4);
        Rational b(15, 8);
        Rational c = a / b;
        bool equal = c == Rational(2, 3);
        if (!equal) {
            std::cout << "5/4 / 15/8 != 2/3" << std::endl;
            return 2;
        }
    }

    {
        std::ostringstream output;
        output << Rational(-6, 8);
        if (output.str() != "-3/4") {
            std::cout << "Rational(-6, 8) should be written as \"-3/4\"" << std::endl;
            return 1;
        }
    }

    {
        std::istringstream input("5/7");
        Rational r;
        input >> r;
        bool equal = r == Rational(5, 7);
        if (!equal) {
            std::cout << "5/7 is incorrectly read as " << r << std::endl;
            return 2;
        }
    }

    {
        std::istringstream input("5/7 10/8");
        Rational r1, r2;
        input >> r1 >> r2;
        bool correct = r1 == Rational(5, 7) && r2 == Rational(5, 4);
        if (!correct) {
            std::cout << "Multiple values are read incorrectly: " << r1 << " " << r2 << std::endl;
            return 3;
        }

        input >> r1;
        input >> r2;
        correct = r1 == Rational(5, 7) && r2 == Rational(5, 4);
        if (!correct) {
            std::cout << "Read from empty stream shouldn't change arguments: " << r1 << " " << r2 << std::endl;
            return 4;
        }
    }

    {
        const std::set<Rational> rs = {{1, 2}, {1, 25}, {3, 4}, {3, 4}, {1, 2}};
        if (rs.size() != 3) {
            std::cout << "Wrong amount of items in the set" << std::endl;
            return 1;
        }

        std::vector<Rational> v;
        for (auto x : rs) {
            v.push_back(x);
        }
        if (v != std::vector<Rational>{{1, 25}, {1, 2}, {3, 4}}) {
            std::cout << "Rationals comparison works incorrectly" << std::endl;
            return 2;
        }
    }

    {
        std::map<Rational, int> count;
        ++count[{1, 2}];
        ++count[{1, 2}];

        ++count[{2, 3}];

        if (count.size() != 2) {
            std::cout << "Wrong amount of items in the map" << std::endl;
            return 3;
        }
    }

    try {
        Rational r(1, 0);
        std::cout << "Doesn't throw in case of zero denominator" << std::endl;
        return 1;
    } catch (std::invalid_argument&) {
    }

    try {
        auto x = Rational(1, 2) / Rational(0, 1);
        std::cout << "Doesn't throw in case of division by zero" << std::endl;
        return 2;
    } catch (std::domain_error&) {
    }

    {
        Rational r1, r2;
        char operation;

        try {
            std::cin >> r1 >> operation >> r2;

            if(operation == '+'){
                std::cout << r1 + r2 << '\n';
            } else if (operation == '-'){
                std::cout << r1 - r2 << '\n';
            } else if (operation == '/'){
                try{
                    std::cout << r1 / r2 << '\n';
                }catch(std::domain_error& error){
                    std::cout << error.what() << '\n';
                }
            }else{
                std::cout << r1 * r2 << '\n';
            }
        }catch(std::invalid_argument& exception){
            std::cout << exception.what() << '\n';
        }
    }


    std::cout << "OK" << std::endl;
}