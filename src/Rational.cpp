//
// Created by Legion on 4/20/2023.
//
#include <algorithm>
class Rational {
public:
    Rational() {
        numerator = 0;
        denominator = 1;
    }

    Rational(int numerator_, int denominator_) {

        bool numerator_positive = numerator_ > 0;
        bool denominator_positive = denominator_ > 0;

        int a_num = abs(numerator_);
        int a_den = abs(denominator_);

        int common_divider = gcd(a_num, a_den);

        if(common_divider != 1){
            while(a_num % common_divider == 0 && a_den % common_divider == 0){
                a_num /= common_divider;
                a_den /= common_divider;
            }
        }

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

private:
    // Добавьте поля
    int numerator;
    int denominator;

    int gcd(int a, int b) {
        if (b == 0)
            return a;
        return gcd(b, a % b);
    }

};