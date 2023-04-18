//
// Created by eliya on 16/04/2023.
//
#ifndef EX_3_FRACTION_HPP
#define EX_3_FRACTION_HPP
namespace ariel{}
#include <string>
using namespace std;

    class Fraction {
    private:
        int a;
        int b;


    public:

        int gcd(int abc, int bcd);

        int getUp();

        int getDown();

        Fraction(int abc, int bcd);

        Fraction();


        Fraction operator+(const Fraction &) const;

        Fraction operator+(float) const;

        friend Fraction operator+( float, const Fraction &);


        Fraction operator-(const Fraction &) const;

        Fraction operator-( float) const;

        friend Fraction operator-( float, const Fraction &);


        Fraction operator/(const Fraction &) const;

        Fraction operator/( float) const;

        friend Fraction operator/( float, const Fraction &);


        Fraction operator*(const Fraction &) const;

        Fraction operator*( float) const;

        friend Fraction operator*( float, const Fraction &);

        bool operator==(const Fraction &) const;

        bool operator==(float) const;

        friend bool operator==(float, const Fraction &);

        bool operator>(const Fraction &) const;

        bool operator>(float) const;

        friend bool operator>(float, const Fraction &);

        bool operator<(const Fraction &) const;

        bool operator<(float) const;

        friend bool operator<(float, const Fraction &);

        bool operator>=(const Fraction &) const;

        bool operator>=(float) const;

        friend bool operator>=(float, const Fraction &);

        bool operator<=(const Fraction &) const;

        bool operator<=(float) const;

        friend bool operator<=(float, const Fraction &);

        Fraction operator++(int);

        Fraction operator--(int);

        Fraction operator++();

        Fraction operator--();

        friend std::ostream &operator<<(std::ostream &output, const Fraction &other);


    };



#endif //EX_3_FRACTION_HPP
