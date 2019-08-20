#include "../std_lib_facilities.h"
#include "fraction.h"

//seokho Han 201761541
//COMP2510 ass3
//Fraction class - Test file

int main()
{
    Fraction half = Fraction(5,10);
    Fraction half2 = Fraction(1,2);
    Fraction third = Fraction(1,3);
    Fraction defaultF = Fraction(); //default constructor
    Fraction negative = Fraction(10, -20); //negative denominator
    Fraction reduced = half.reduce(); //reduce to the simplest form
    //operators overloaded
    Fraction addition = half + half2;
    Fraction subtration = half - third;
    Fraction muliplication = half * third;
    Fraction division = half / third;
    bool testEqualFail = (half == third);
    bool testUnequalFail = (third != half2);

    cout << "test print() half = " << half.print() << endl;
    cout << "test default : " << defaultF.print() << endl;
    cout << "test negative denominator (10/-20) : " << negative.print() << endl;
    cout << "test reduce() 5/10 = " << reduced.print() << endl;
    cout << "test + operator (5/10 + 1/2) : " << addition.print() << endl;
    cout << "test - operator (5/10 - 1/3) : " << subtration.print() << endl;
    cout << "test * operator (5/10 * 1/3) : " << muliplication.print() << endl;
    cout << "test / operator (5/10 / 1/3) : " << division.print() << endl;
    cout << "test half == third (expect 0 for false).  Result: " << testEqualFail << "\n";
    cout << "test third != half2 (expect 1 for false).  Result: " << testUnequalFail << "\n";
    return 0;
}

