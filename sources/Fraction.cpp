//
// Created by eliya on 16/04/2023.
//
#include "Fraction.hpp"
#include <string>
#include <ostream>
#include <iostream>
#include <cmath>
#include <limits.h>
#include <algorithm>

using namespace std;


int Fraction:: gcd(int a,int b) {
    int a_=abs(a);
    int b_=abs(b);
    return __gcd(a_,b_);
};


void Fraction:: reduce(){
    int max_int = std::numeric_limits<int>::max();
    int min_int = std::numeric_limits<int>::min();
        if(this->up==0){
           return;
        }
    if(up==min_int){
        return;
    }
    int GCD=gcd(this->getNumerator(),this->getDenominator());
    int up_=this->up,down_=this->down;
    this->up=up_/GCD;
    this->down=down_/GCD;
}

bool Fraction::does_overflow(int abc, int bcd)const
{
    if (abc >= 0) {
        if (bcd > (INT_MAX - abc)) {
            return true;
        }
    } else {
        if (bcd < (INT_MIN - abc)) {
            return true;
        }
    }
    return false;
}



 int Fraction::getNumerator()const {
    return this->up;
};

 int Fraction::getDenominator()const {
    return this->down;
};







Fraction::Fraction(int up, int down) {

    if ((down == 0)&&(up!=0)) {
        throw invalid_argument("Denominator cannot be zero");
    }
    else if( (up>0) && (down<0) ){
        up*=-1;
        down*=-1;
    }
    else if( (up<0) && (down<0) ){
        up*=-1;
        down*=-1;
    }
    else if(((up==0)) && (down<0||down>0||down==0) ){
        up=0;
        down=0;
    }
    this->up=up;
    this->down=down;
    this->reduce();
};

Fraction::Fraction() {
    this->up=1;
    this->down=1;
};

Fraction::Fraction(float number) {
    int n = (int)number;
    int num = round((number - n) * 1000);
    int deno = 1000;
    if( num == 0)
    {
        up = (int) number;
        down = 1;
    } else
    {
        int gcdd = gcd(num, deno);
        up = (n * deno + num) / gcdd;
        down = deno / gcdd;
    }
    reduce();
}
Fraction::Fraction(const Fraction *fraction){
    this->up=fraction->up;
    this->down=fraction->down;
}








const Fraction Fraction::operator+(const Fraction& other) const{
    if ((does_overflow(up,other.up)==true)){
        throw std::overflow_error("Overflow detected in addition");
    }
    int up_=this->up*other.down+this->down*other.up;
    int down_=this->down*other.down;
    Fraction temp(up_,down_);
    temp.reduce();
    return temp;
};

const Fraction Fraction::operator+(const float other) const {
    Fraction o(other);
    int up_=this->up*o.down+this->down*o.up;
    int down_=this->down*o.down;
    Fraction temp(up_,down_);
    temp.reduce();
    return temp;
};


 const Fraction operator+(const float fother, const Fraction &other){
     return other.operator+(fother);
};







const Fraction Fraction::operator-(const Fraction &other) const {
    long long num = static_cast<long long>(up) * other.down -
                    static_cast<long long>(other.up) * down;
    if ((does_overflow(up,other.down)==true) || (does_overflow(down,other.up)==true)||
        (does_overflow(this->up*other.down,this->down*other.up)==true)|| does_overflow(this->up,-(other.up*this->down))) {
        throw std::overflow_error("Overflow_error");
    }
    int up_=(this->up*other.down)-(this->down*other.up);
    int down_=this->down*other.down;
    Fraction temp(up_,down_);
    temp.reduce();
    return temp;
};
const Fraction Fraction::operator-( float fother) const {
    Fraction o(fother);
    return this->operator-(o);
};
Fraction operator-(const float fother, const Fraction & other){
    return Fraction(fother)-other;
};







const Fraction Fraction::operator/(const Fraction &other) const {
    //(a/b) / (c/d) => (a*d)/(b*c)
    // if num is 0 then cant divide
    if ((up != 0 && other.up == 0)||(up != 0 && other.down == 0)) {
        throw std::runtime_error("Division by zero");
    }

    if ((up > 0 && other.up > (std::numeric_limits<int>::max() / down)) ||
        (up < 0 && other.up < (std::numeric_limits<int>::min() / down)))
    {
        throw std::overflow_error("Overflow detected in division");
    }


    if ((up > (std::numeric_limits<int>::max() / other.down)) ||
        (up < (std::numeric_limits<int>::min() / other.down))) {
        throw std::overflow_error("Overflow detected in division");
    }


    int num = up * other.down;
    int den = down * other.up;

    return Fraction(num, den);

};

const Fraction Fraction::operator/(const float fother) const {
    if (fother==0){
        throw runtime_error("division by zero not allowed");
    }
    Fraction o(fother);
    return this->operator/(o);
};

const Fraction operator/(const float fotehr, const Fraction &other){
    if (other.up==0||other.down==0){
        throw runtime_error("division by zero not allowed");
    }
    return Fraction(fotehr)/other;
};









const Fraction Fraction::operator*(const Fraction &other) const {
    // Check if numerator or denominator of either fraction is 0, and return 0 if so
    if (up == 0 || other.up == 0 || down == 0 || other.down == 0) {
        return Fraction(0,0);
    }

    // Calculate the new numerator and denominator after multiplication
    int num = up * other.up;
    int den = down * other.down;

    // Check for integer overflow
    if (num / other.up != up || num / up != other.up || den / other.down != down) {
        throw std::overflow_error("Overflow detected in multiplication");
    }
    return Fraction(num, den);
};

const Fraction Fraction::operator*(const float fother) const {
    Fraction o(fother);
    return this->operator*(o);
};

const Fraction operator*(const float fotehr, const Fraction &other){
    return Fraction(fotehr)*other;
};






bool Fraction::operator==(const Fraction &other)const{
    Fraction temp_1(this);
    Fraction temp_2(other);
    temp_1.up=this->up*other.down,temp_1.down=this->down*other.down;
    temp_2.up=other.up*this->down,temp_2.down=this->down*other.down;
    if((temp_1.down==0||temp_2.down==0)&&(temp_1.up!=0&&temp_2.up!=0)) {
        throw invalid_argument("Denominator cannot be zero");
    }
    float frac1 = (float)this->up / this->down;
    float frac2 = (float)other.up / other.down;
    float tolerance = 0.001;
    if((temp_1.down==0&&temp_2.down==0)&&(temp_1.up==0&&temp_2.up==0)) {
        return true;
    }
    if((std::abs(frac1 - frac2) < tolerance)){
        return true;
    } else{
        return false;
    }
};
bool Fraction::operator==(float fother) const {
    Fraction o(fother);
    return this->operator==(o);
};
bool operator==(float fother, const Fraction &other){
    return Fraction(fother)==other;
}






bool Fraction::operator!=(const Fraction& other) const {
    return !(*this == other);
}

bool Fraction:: operator!=(const float & other)const{
    return !(*(this)==Fraction(other));
}

bool operator!=(const float& fother, const Fraction& other){
    return !(Fraction(fother)==other);
}









bool Fraction::operator>(const Fraction &other) const {
    Fraction temp_1(this);
    Fraction temp_2(other);
    temp_1.up=this->up*other.down,temp_1.down=this->down*other.down;
    temp_2.up=other.up*this->down,temp_2.down=this->down*other.down;
    if(temp_1.down==0||temp_2.down==0){
        throw invalid_argument("Denominator cannot be zero");
    } else if(temp_1.up>temp_2.up&&temp_2.up<temp_1.up){
        return true;
    } else{
        return false;
    }
    return true;
};

bool Fraction::operator>(float fother) const {
    Fraction o(fother);
    return this->operator>(o);
};

bool operator>(float fother, const Fraction &other){
    return Fraction(fother)>other;
};







bool Fraction::operator<(const Fraction &other) const {
    Fraction temp_1(this);
    Fraction temp_2(other);
    temp_1.up=this->up*other.down,temp_1.down=this->down*other.down;
    temp_2.up=other.up*this->down,temp_2.down=this->down*other.down;
    if((temp_1.down==0||temp_2.down==0)&&(temp_1.up!=0&&temp_2.up!=0)){
        throw invalid_argument("Denominator cannot be zero");
    } else if(temp_1.up<temp_2.up&&temp_2.up>temp_1.up){
        return true;
    } else{
        return false;
    }
};

bool Fraction::operator<(float fother) const {
    Fraction o(fother);
    return this->operator<(o);
};
bool operator<(float fother, const Fraction &other){
    return Fraction(fother)<other;
};








bool Fraction::operator>=(const Fraction &other) const {
    Fraction temp_1(this);
    Fraction temp_2(other);
    temp_1.up=this->up*other.down,temp_1.down=this->down*other.down;
    temp_2.up=other.up*this->down,temp_2.down=this->down*other.down;
    if((temp_1.down==0||temp_2.down==0)&&(temp_1.up!=0&&temp_2.up!=0)){
        throw invalid_argument("Denominator cannot be zero");
    } else if(temp_1.up>temp_2.up&&temp_2.up<temp_1.up||temp_1.up==temp_2.up){
        return true;
    } else{
        return false;
    }
};

bool Fraction::operator>=(float fother) const {
    Fraction o(fother);
    return this->operator>=(o);
};
bool operator>=(float fother, const Fraction &other){
    return Fraction(fother)>=other;
};








bool Fraction::operator<=(const Fraction &other) const {
    Fraction temp_1(this);
    Fraction temp_2(other);
    temp_1.up=this->up*other.down,temp_1.down=this->down*other.down;
    temp_2.up=other.up*this->down,temp_2.down=this->down*other.down;
    if((temp_1.down==0||temp_2.down==0)&&(temp_1.up!=0&&temp_2.up!=0)){
        throw invalid_argument("Denominator cannot be zero");
    } else if(temp_1.up<temp_2.up&&temp_2.up>temp_1.up||temp_1.up==temp_2.up){
        return true;
    } else{
        return false;
    }
};

bool Fraction::operator<=(float fother) const {
    Fraction o(fother);
    return this->operator<=(o);
};
bool operator<=(float fother, const Fraction &other){
    return Fraction(fother)<=other;
};






Fraction & Fraction::operator++() {
    int plus=this->down;
    this->up=this->up+plus;
    return *this;
};
Fraction Fraction::operator++(int)
{
    Fraction temp(this->getNumerator(),this->getDenominator());
    ++(*this);
    return temp;
}

Fraction & Fraction::operator--() {
    int minus=this->down;
    this->up=this->up-minus;
    this->reduce();
    return *this;
};
Fraction Fraction::operator--(int)
{
    Fraction temp(this->getNumerator(),this->getDenominator());
    --(*this);
    return temp;
}



ostream& operator<<(ostream& output, const Fraction& other){
    Fraction temp(other.getNumerator(), other.getDenominator());
    temp.reduce();
    output<<  temp.getNumerator() << "/" << temp.getDenominator();
    return output;
};

istream& operator >>(istream& inptstream,  Fraction& fraction){
    int numitor = 0, denitor = 0;

    inptstream >> numitor >> denitor;

    if (inptstream.fail())
        throw std::runtime_error("Invalid input");

    else if (denitor == 0)
        throw std::runtime_error("Denominator can't be zero");

    else if (denitor < 0)
    {
        numitor *= -1;
        denitor *= -1;
    }

    fraction.up = numitor;
    fraction.down = denitor;
    fraction.reduce();

    return inptstream;
}






