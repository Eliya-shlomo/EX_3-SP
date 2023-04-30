//
// Created by eliya on 16/04/2023.
//
#include "Fraction.hpp"
#include <string>
#include <ostream>
using namespace std;


int Fraction:: gcd(int a,int b) {
    int result = min(a, b); // Find Minimum of a and b
    while (result > 0) {
        if (a % result == 0 && b % result == 0) {
            break;
        }
        result--;
    }
    return result; // return gcd of a and b
};

    void Fraction:: reduce(){
    int GCD=gcd(this->getNumerator(),this->getDenominator());
    this->up=this->getNumerator()/GCD;
    this->down=this->getNumerator()/GCD;

}



 int Fraction::getNumerator()const {
    return this->up;
};

 int Fraction::getDenominator()const {
    return this->down;
};







Fraction::Fraction(int up, int down) {
    if(this->down==0){
        throw invalid_argument("Denominator cannot be zero");
    }
    this->up=up;
    this->down=down;
};

Fraction::Fraction() {
    this->up=1;
    this->down=1;
};

Fraction::Fraction(float number) {
    int Numerator  = int(number)*1000+(int)(number * 1000) % 1000;
    this->up=Numerator ;
    this->down=1000;
}








const Fraction Fraction::operator+(const Fraction& other) const{
    if(this->down==0||other.down==0){
        throw invalid_argument("Denominator cannot be zero");
    }
    int up_=this->up*other.down+this->down*other.up;
    int down_=this->down*other.down;
    Fraction temp(up_,down_);
    temp.reduce();
    return temp;
};

const Fraction Fraction::operator+(const float other) const {
    if(this->down==0||other==0){
        throw invalid_argument("Denominator cannot be zero");
    }
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
    if(this->down==0||other.down==0){
        throw invalid_argument("Denominator cannot be zero");
    }
    int up_=this->up*other.down-this->down*other.up;
    int down_=this->down*other.down;
    Fraction temp(up_,down_);
    temp.reduce();
    return temp;
};
const Fraction Fraction::operator-(const float fother) const {
    Fraction o(fother);
    int up_=this->up*o.down-this->down*o.up;
    int down_=this->down*o.down;
    Fraction temp(up_,down_);
    temp.reduce();
    return temp;
};
const Fraction operator-(const float fother, const Fraction &otehr){
    return otehr.operator-(fother);
};







const Fraction Fraction::operator/(const Fraction &other) const {
    if(this->down==0||other.down==0){
        throw invalid_argument("Denominator cannot be zero");
    }
    int up_=this->up*other.down;
    int down_=this->down*other.up;
    Fraction temp(up_,down_);
    temp.reduce();
    return temp;
};

const Fraction Fraction::operator/(const float fother) const {
    Fraction o(fother);
    int up_=this->up*o.down;
    int down_=this->down*o.up;
    Fraction temp(up_,down_);
    temp.reduce();
    return temp;
};

const Fraction operator/(const float fotehr, const Fraction &other){
    return other.operator/(fotehr);
};









const Fraction Fraction::operator*(const Fraction &other) const {
    if(this->down==0||other.down==0){
        throw invalid_argument("Denominator cannot be zero");
    }
    int up_=this->up*other.up;
    int down_=this->down*other.down;
    Fraction temp(up_,down_);
    temp.reduce();
    return temp;
};

const Fraction Fraction::operator*(const float fother) const {
    Fraction o(fother);
    if(this->down==0||o.down==0){
        throw invalid_argument("Denominator cannot be zero");
    }
    int up_=this->up*o.up;
    int down_=this->down*o.down;
    Fraction temp(up_,down_);
    temp.reduce();
    return temp;
};

const Fraction operator*(const float fotehr, const Fraction &other){
    return other.operator*(fotehr);
};







bool Fraction::operator==(const Fraction &other) const {
    Fraction temp_1;
    Fraction temp_2;
    temp_1.up=this->up,temp_1.down=this->down, temp_1.reduce();
    temp_2.up=other.up,temp_2.down=other.down, temp_2.reduce();
    if(temp_1.down==0||temp_2.down==0){
        throw invalid_argument("Denominator cannot be zero");
    } else if(temp_1.up==temp_2.up&&temp_1.down==temp_2.down){
        return true;
    } else{
        return false;
    }
};

bool Fraction::operator==(float fother) const {
    Fraction o(fother);
    Fraction temp_1;
    Fraction temp_2;
    temp_1.up=this->up,temp_1.down=this->down, temp_1.reduce();
    temp_2.up=o.up,temp_2.down=o.down, temp_2.reduce();
    if(temp_1.down==0||temp_2.down==0){
        throw invalid_argument("Denominator cannot be zero");
    } else if(temp_1.up==temp_2.up&&temp_1.down==temp_2.down){
        return true;
    } else{
        return false;
    }
};
bool operator==(float fother, const Fraction &other){
    return other.operator==(fother);
}




bool Fraction::operator>(const Fraction &other) const {
    Fraction temp_1;
    Fraction temp_2;
    temp_1.up=this->up,temp_1.down=this->down, temp_1.reduce();
    temp_2.up=other.up,temp_2.down=other.down, temp_2.reduce();
    temp_1.up=temp_1.up*temp_2.down;
    temp_2.up=temp_2.up*temp_1.down;
    if(temp_1.down==0||temp_2.down==0){
        throw invalid_argument("Denominator cannot be zero");
    } else if(temp_1.up>temp_2.up&&temp_2.up<temp_1.up){
        return true;
    } else{
        return false;
    }
};

bool Fraction::operator>(float fother) const {
    Fraction o(fother);
    Fraction temp_1;
    Fraction temp_2;
    temp_1.up=this->up,temp_1.down=this->down, temp_1.reduce();
    temp_2.up=o.up,temp_2.down=o.down, temp_2.reduce();
    temp_1.up=temp_1.up*temp_2.down;
    temp_2.up=temp_2.up*temp_1.down;
    if(temp_1.down==0||temp_2.down==0){
        throw invalid_argument("Denominator cannot be zero");
    } else if(temp_1.up>temp_2.up&&temp_2.up<temp_1.up){
        return true;
    } else{
        return false;
    }
};

bool operator>(float fother, const Fraction &other){
    return other.operator>(fother);
};





bool Fraction::operator<(const Fraction &other) const {
    Fraction temp_1;
    Fraction temp_2;
    temp_1.up=this->up,temp_1.down=this->down, temp_1.reduce();
    temp_2.up=other.up,temp_2.down=other.down, temp_2.reduce();
    temp_1.up=temp_1.up*temp_2.down;
    temp_2.up=temp_2.up*temp_1.down;
    if(temp_1.down==0||temp_2.down==0){
        throw invalid_argument("Denominator cannot be zero");
    } else if(temp_1.up<temp_2.up&&temp_2.up>temp_1.up){
        return true;
    } else{
        return false;
    }
};

bool Fraction::operator<(float fother) const {
    Fraction o(fother);
    Fraction temp_1;
    Fraction temp_2;
    temp_1.up=this->up,temp_1.down=this->down, temp_1.reduce();
    temp_2.up=o.up,temp_2.down=o.down, temp_2.reduce();
    temp_1.up=temp_1.up*temp_2.down;
    temp_2.up=temp_2.up*temp_1.down;
    if(temp_1.down==0||temp_2.down==0){
        throw invalid_argument("Denominator cannot be zero");
    } else if(temp_1.up>temp_2.up&&temp_2.up<temp_1.up){
        return true;
    } else{
        return false;
    }
};
bool operator<(float fother, const Fraction &other){
    return other.operator>(fother);
};








bool Fraction::operator>=(const Fraction &other) const {
    Fraction temp_1;
    Fraction temp_2;
    temp_1.up=this->up,temp_1.down=this->down, temp_1.reduce();
    temp_2.up=other.up,temp_2.down=other.down, temp_2.reduce();
    temp_1.up=temp_1.up*temp_2.down;
    temp_2.up=temp_2.up*temp_1.down;
    if(temp_1.down==0||temp_2.down==0){
        throw invalid_argument("Denominator cannot be zero");
    } else if(temp_1.up>temp_2.up&&temp_2.up<temp_1.up||temp_1.up==temp_2.up){
        return true;
    } else{
        return false;
    }
};

bool Fraction::operator>=(float fother) const {
    Fraction o(fother);
    Fraction temp_1;
    Fraction temp_2;
    temp_1.up=this->up,temp_1.down=this->down, temp_1.reduce();
    temp_2.up=o.up,temp_2.down=o.down, temp_2.reduce();
    temp_1.up=temp_1.up*temp_2.down;
    temp_2.up=temp_2.up*temp_1.down;
    if(temp_1.down==0||temp_2.down==0){
        throw invalid_argument("Denominator cannot be zero");
    } else if(temp_1.up>temp_2.up&&temp_2.up<temp_1.up||temp_1.up==temp_2.up){
        return true;
    } else{
        return false;
    }
};
bool operator>=(float fother, const Fraction &other){
    return other.operator>=(fother);
};








bool Fraction::operator<=(const Fraction &other) const {
    Fraction temp_1;
    Fraction temp_2;
    temp_1.up=this->up,temp_1.down=this->down, temp_1.reduce();
    temp_2.up=other.up,temp_2.down=other.down, temp_2.reduce();
    temp_1.up=temp_1.up*temp_2.down;
    temp_2.up=temp_2.up*temp_1.down;
    if(temp_1.down==0||temp_2.down==0){
        throw invalid_argument("Denominator cannot be zero");
    } else if(temp_1.up<temp_2.up&&temp_2.up>temp_1.up||temp_1.up==temp_2.up){
        return true;
    } else{
        return false;
    }
};

bool Fraction::operator<=(float fother) const {
    Fraction o(fother);
    Fraction temp_1;
    Fraction temp_2;
    temp_1.up=this->up,temp_1.down=this->down, temp_1.reduce();
    temp_2.up=o.up,temp_2.down=o.down, temp_2.reduce();
    temp_1.up=temp_1.up*temp_2.down;
    temp_2.up=temp_2.up*temp_1.down;
    if(temp_1.down==0||temp_2.down==0){
        throw invalid_argument("Denominator cannot be zero");
    } else if(temp_1.up<temp_2.up&&temp_2.up>temp_1.up||temp_1.up==temp_2.up){
        return true;
    } else{
        return false;
    }};
bool operator<=(float fother, const Fraction &other){
    return other.operator<=(fother);
};






Fraction & Fraction::operator++() {
    int plus=this->down;
    this->up=this->up+plus;
    return *this;
};
Fraction Fraction::operator++(int)
{
    this->up += this->down;
    Fraction fr = (*this);
    fr.reduce();
    return fr;
}

Fraction & Fraction::operator--() {
    int minus=this->down;
    this->up=this->up-minus;
    this->reduce();
    return *this;
};
Fraction Fraction::operator--(int)
{
    this->up -= this->down;
    Fraction fr = (*this);
    fr.reduce();
    return fr;
}



ostream& operator<<(ostream& output, const Fraction& other){
    Fraction temp(other.getNumerator(), other.getDenominator());
    temp.reduce();
    output << temp.getNumerator() << "/" << temp.getDenominator();
    return output;
};

istream& operator >>(istream& in,  Fraction& frac){
    int fracdnum;
    int fracnum;
    int num_read = scanf("%d/%d", &fracnum, &fracdnum);
    if( num_read ==1){
        fracdnum=1;
        Fraction(fracnum,fracdnum);
    }
    else if (num_read == 2){
        Fraction(fracnum,fracdnum);
    }

    return in;
}






