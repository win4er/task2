#include "task2.h"

int Rational::gcd(int a, int b){
    if (a > b){
      a = a + b;
      b = a - b;
      a = a - b;
    }
    if ((a == (b - a)) or (a == b)) {
      return a;
    }
    return gcd(a, b - a);
}

Rational::Rational(){
    numerator_ = 0;
	denominator_ = 1;
}

Rational::Rational(int numerator){
    numerator_ = numerator;
    denominator_ = 1;
}

Rational::Rational(int numerator, int denominator){
    numerator_ = numerator;
    denominator_ = denominator;
}

Rational Rational::Add(const Rational& a, const Rational& b){
    Rational r;
    int GCD = r.gcd(a.denominator(), b.denominator());
    int numer = a.numerator() * b.denominator() / GCD + b.numerator() * a.denominator() / GCD;
    int denomer = a.denominator() * b.denominator() / GCD;
    return Rational(numer, denomer);
}

int Rational::numerator() const {
    return numerator_;
}

int Rational::denominator() const {
    return denominator_;
}
