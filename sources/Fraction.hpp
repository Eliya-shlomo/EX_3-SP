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

        int up;
        int down;
        int gcd(int, int);


    protected:
        void reduce();

    public:


        int getNumerator()const;

        int getDenominator()const;

        Fraction(int up_, int down);

        Fraction();

        Fraction(float number);

        Fraction(const Fraction *fraction);


        const Fraction operator+(const Fraction &other) const;

        const Fraction operator+(float other) const;

        friend const Fraction operator+( float fother, const Fraction &otehr);


        const Fraction operator-(const Fraction &) const;

        const Fraction operator-( float) const;

        friend Fraction operator-( float ,const Fraction&);


        const Fraction operator/(const Fraction &) const;

        const Fraction operator/( float) const;

        friend const Fraction operator/( float, const Fraction &);


        const Fraction operator*(const Fraction &) const;

        const Fraction operator*( float) const;

        friend const Fraction operator*( float, const Fraction &);


        bool operator==(const Fraction &) const;

        bool operator==(float) const;

        friend  bool operator==(float, const Fraction &);


        bool operator!=(const Fraction& other) const;

        bool operator!=(const float& other) const;

        friend bool operator!=(const float& num, const Fraction& other);


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



        Fraction & operator++();
        Fraction operator++(int);

        Fraction & operator--();
        Fraction operator--(int);


        friend std::ostream &operator<<(std::ostream &output, const Fraction &other);

        friend istream& operator >>(istream& in_,  Fraction& frac);

        bool does_overflow(int abc, int bcd) const;




    };



#endif //EX_3_FRACTION_HPP
