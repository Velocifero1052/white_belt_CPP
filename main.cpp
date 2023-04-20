#include <algorithm>
#include <iostream>
#include <vector>

using std::string;
using std::vector;
using std::cin;
using std::cout;
using std::endl;

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

int main() {

    {
        const Rational r(3, 10);
        if (r.Numerator() != 3 || r.Denominator() != 10) {
            cout << "Rational(3, 10) != 3/10" << endl;
            return 1;
        }
    }

    {
        const Rational r(8, 12);
        if (r.Numerator() != 2 || r.Denominator() != 3) {
            cout << "Rational(8, 12) != 2/3" << endl;
            return 2;
        }
    }

    {
        const Rational r(-4, 6);
        if (r.Numerator() != -2 || r.Denominator() != 3) {
            cout << "Rational(-4, 6) != -2/3" << endl;
            return 3;
        }
    }
    {
        const Rational r(4, -6);
        if (r.Numerator() != -2 || r.Denominator() != 3) {
            cout << "Rational(4, -6) != -2/3" << endl;
            return 3;
        }
    }

    {
        const Rational r(0, 15);
        if (r.Numerator() != 0 || r.Denominator() != 1) {
            cout << "Rational(0, 15) != 0/1" << endl;
            return 4;
        }
    }

    {
        const Rational r(-2, -4);
        if (r.Numerator() != 1 || r.Denominator() != 2) {
            cout << "Rational(-2, -4) != 1/2" << endl;
            return 4;
        }
    }

    {
        const Rational defaultConstructed;
        if (defaultConstructed.Numerator() != 0 || defaultConstructed.Denominator() != 1) {
            cout << "Rational() != 0/1" << endl;
            return 5;
        }
    }



    cout << "OK" << endl;

    return 0;
}

