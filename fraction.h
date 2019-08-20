#ifndef __FRACTION_H
#define __FRACTION_H
#include "../std_lib_facilities.h"

//seokho Han 201761541
//COMP2510 ass3
//Fraction class - header file

class Fraction
{
    int numerator;
    int denominator;
    
public:
    Fraction(int, int);
    Fraction();
    void standardize();
    string print() const;
    Fraction reduce() const;
    Fraction operator+(const Fraction& f) const;
    Fraction operator-(const Fraction& f) const;
    Fraction operator*(const Fraction& f) const;
    Fraction operator/(const Fraction& f) const;
    bool operator==(const Fraction& f) const;
    bool operator!=(const Fraction& f) const;
};
#endif