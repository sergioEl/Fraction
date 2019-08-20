#include "../std_lib_facilities.h"
#include "fraction.h"

//seokho Han 201761541
//COMP2510 ass3
//Fraction class - implementation file

int gcd(int n, int d)  // find the greatest common divisor
{
    if (n == 0) return d;
    if (d == 0) return n;
    if(n == d)
    {
        return d;
    }

    if(n > d)
    {
        return gcd(n - d, d);
    }
    return gcd(n, d-n);
}

Fraction::Fraction(int n, int d)// constructor
    : numerator(n), denominator(d)
    {
        standardize();
    }

const Fraction& default_fraction()
{
    static Fraction f{0, 1};
    return f;
}

Fraction::Fraction()// default constructor
    : numerator{default_fraction().numerator}, denominator{default_fraction().denominator}
    {
    }

void Fraction::standardize()
{
    if (denominator < 0)
    {
        denominator *= -1;
        numerator *= -1;
    }
}

string Fraction::print() const
{
    string s;
    s = s + to_string(numerator) + "/" + to_string(denominator);

    return s;
}

Fraction Fraction::reduce() const
{
    int divisor = gcd(numerator, denominator);
    int n, d;
    n = numerator / divisor;
    d = denominator / divisor;
    Fraction newF{n, d};

    return newF;
}

Fraction Fraction::operator+(const Fraction& f) const
{
    int n, d;
    n = numerator * f.denominator + f.numerator * denominator;
    d = denominator * f.denominator;
    Fraction newF{n,d};

    return newF.reduce();
}

Fraction Fraction::operator-(const Fraction& f) const
{
    int n,d;
    n = numerator * f.denominator - f.numerator * denominator;
    d = denominator * f.denominator;
    Fraction newF{n,d};

    return newF.reduce();
}

Fraction Fraction::operator*(const Fraction& f) const
{
    int n,d;
    n = numerator * f.numerator;
    d = denominator * f.denominator;
    Fraction newF{n,d};

    return newF.reduce();
}

Fraction Fraction::operator/(const Fraction& f) const
{
    int n,d;
    n = this->numerator * f.denominator;
    d = this->denominator * f.numerator;
    Fraction newF{n,d};

    return newF.reduce();
}

bool Fraction::operator==(const Fraction& f) const
{
    Fraction reduced = reduce();
    Fraction other = f.reduce();
    return (reduced.numerator == other.numerator && reduced.denominator == other.denominator) ? true : false;
    //return (double) numerator/denominator == (double) f.numerator/f.denominator;
}

bool Fraction::operator!=(const Fraction& f) const
{
    return !(*this == f);
}
