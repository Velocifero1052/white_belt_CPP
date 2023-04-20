#include <algorithm>
#include <iostream>
#include <vector>
#include <sstream>
#include <map>
#include <set>

using std::string;
using std::vector;
using std::cin;
using std::cout;
using std::endl;
using std::map;
using std::set;
using std::istringstream;
using std::ostringstream;
using std::istream;
using std::ostream;
using std::runtime_error;

class Rational {
public:
    Rational() {
        numerator = 0;
        denominator = 1;
    }

    Rational(int numerator_, int denominator_) {
        if(denominator_ == 0)
            throw std::invalid_argument("");

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
            throw std::domain_error("");
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


int main() {


    cout << "OK" << endl;
    return 0;
}

