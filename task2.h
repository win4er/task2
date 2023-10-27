#ifndef TASK2_H
#define TASK2_H

#include <ostream>
class Rational {
    private:
	int numerator_;
	int denominator_;
        int gcd(int a, int b);
    public:
	Rational();
	Rational(int numerator);
	Rational(int numerator, int denominator);
	

        static Rational Add(const Rational& a, const Rational& b);

        int numerator() const;
	int denominator() const;
};

Rational operator+(const Rational& r1, const Rational& r2);
Rational operator-(const Rational& r1, const Rational& r2);
Rational operator/(const Rational& r1, const Rational& r2);
Rational operator*(const Rational& r1, const Rational& r2);
std::ostream &operator<<(std::ostream &os, const Rational& num);
#endif
