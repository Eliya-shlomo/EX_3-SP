//
// Created by eliya on 16/04/2023.
//
#ifndef EX_3_FRACTION_HPP
#define EX_3_FRACTION_HPP
namespace ariel{}
#include <string>
using namespace std;
    int gcd(int a,int b);

    class Fraction {
    private:
        int up;
        int down;


    public:

        int gcd(int a,int b);
        int getUp();

        int getDown();

        Fraction(int up, int down);

        Fraction();

        Fraction(float number);


        Fraction operator+(const Fraction &other) const;

        Fraction operator+(float other) const;

        friend Fraction operator+( float fother, const Fraction &otehr);


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

        Fraction simpler(Fraction f)const;
    };



#endif //EX_3_FRACTION_HPP
