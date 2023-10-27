#include "task2.h"

int Rational::gcd(int a, int b){
    if (a > b) {
      a = a + b;
      b = a - b;
      a = a - b;
    }
    if ((a == (b - a)) or (a == b)) {
      return a;
    }
    return gcd(a, b - a);
}

Rational::Rational() {
    numerator_ = 0;
    denominator_ = 1;
}

Rational::Rational(int numerator) {
    numerator_ = numerator;
    denominator_ = 1;
}

Rational::Rational(int numerator, int denominator) {
    int GCD = gcd(numerator, denominator);
    numerator_ = numerator / GCD;
    denominator_ = denominator / GCD;
}

Rational Rational::Add(const Rational& a, const Rational& b) {
    int numer = a.numerator() * b.denominator() + b.numerator() * a.denominator();
    int denomer = a.denominator() * b.denominator();
    return Rational(numer, denomer);
}

int Rational::numerator() const {
    return numerator_;
}

int Rational::denominator() const {
    return denominator_;
}


Rational operator+(const Rational& r1, const Rational& r2) {
    return Rational((r1.numerator() * r2.denominator() + r2.numerator() * r1.denominator()), (r1.denominator() * r2.denominator()));  
}

Rational operator-(const Rational& r1, const Rational& r2) {
    return Rational((r1.numerator() * r2.denominator() - r2.numerator() * r1.denominator()), (r1.denominator() * r2.denominator()));  
}

Rational operator/(const Rational& r1, const Rational& r2) {
    return Rational((r1.numerator() * r2.denominator()), (r1.denominator() * r2.numerator()));  
}

Rational operator*(const Rational& r1, const Rational& r2) {
    return Rational((r1.numerator() * r2.numerator()), (r1.denominator() * r2.denominator()));  
}

std::ostream &operator<<(std::ostream &os, const Rational& num) {
    return os << num.numerator() << "/" << num.denominator();
}
