#include <algorithm>
#include <iostream>
#include <vector>
#include <sstream>

using std::string;
using std::vector;
using std::cin;
using std::cout;
using std::endl;
using std::istringstream;
using std::ostringstream;

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
        return {this->numerator * rhs.denominator, this->denominator * rhs.numerator};
    }

    bool operator==(const Rational& rhs) const{
        return this->numerator == rhs.numerator && this->denominator == rhs.denominator;
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

    {
        Rational r1(4, 6);
        Rational r2(2, 3);
        bool equal = r1 == r2;
        if (!equal) {
            cout << "4/6 != 2/3" << endl;
            return 1;
        }
    }

    {
        Rational a(2, 3);
        Rational b(4, 3);
        Rational c = a + b;
        bool equal = c == Rational(2, 1);
        if (!equal) {
            cout << "2/3 + 4/3 != 2" << endl;
            return 2;
        }
    }

    {
        Rational a(5, 7);
        Rational b(2, 9);
        Rational c = a - b;
        bool equal = c == Rational(31, 63);
        if (!equal) {
            cout << "5/7 - 2/9 != 31/63" << endl;
            return 3;
        }
    }

    {
        Rational a(2, 3);
        Rational b(4, 3);
        Rational c = a * b;
        bool equal = c == Rational(8, 9);
        if (!equal) {
            cout << "2/3 * 4/3 != 8/9" << endl;
            return 1;
        }
    }

    {
        Rational a(5, 4);
        Rational b(15, 8);
        Rational c = a / b;
        bool equal = c == Rational(2, 3);
        if (!equal) {
            cout << "5/4 / 15/8 != 2/3" << endl;
            return 2;
        }
    }



    cout << "OK" << endl;

    return 0;
}

