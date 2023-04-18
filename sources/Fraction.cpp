//
// Created by eliya on 16/04/2023.
//
#include "Fraction.hpp"
#include <string>
#include <ostream>
using namespace std;

Fraction::Fraction(int abc, int bcd) {};

Fraction::Fraction() {};






Fraction Fraction::operator+(const Fraction &) const {
    return Fraction();
};

Fraction Fraction::operator+(const float) const {
    return Fraction();
};
 Fraction operator+(const float, const Fraction &){
     return Fraction();
};





Fraction Fraction::operator-(const Fraction &) const {
    return Fraction();
};
Fraction Fraction::operator-(const float) const {
    return Fraction();
};
Fraction operator-(const float, const Fraction &){
    return Fraction();
};




Fraction Fraction::operator/(const Fraction &) const {
    return Fraction();
};

Fraction Fraction::operator/(const float) const {
    return Fraction();
};
Fraction operator/(const float, const Fraction &){
    return Fraction();
};







Fraction Fraction::operator*(const Fraction &) const {
    return Fraction();
};

Fraction Fraction::operator*(const float) const {
    return Fraction();
};
Fraction operator*(const float, const Fraction &){
    return Fraction();
};








bool Fraction::operator==(const Fraction &) const {
    return false;
};

bool Fraction::operator==(float) const {
    return false;
};
bool operator==(float, const Fraction &){
    return false;
}




bool Fraction::operator>(const Fraction &) const {
    return false;
};

bool Fraction::operator>(float) const {
    return false;
};
bool operator>(float, const Fraction &){
    return false;
};





bool Fraction::operator<(const Fraction &) const {
    return false;
};

bool Fraction::operator<(float) const {
    return false;
};
bool operator<(float, const Fraction &){
    return false;
};





bool Fraction::operator>=(const Fraction &) const {
    return false;
};

bool Fraction::operator>=(float) const {
    return false;
};
bool operator>=(float, const Fraction &){
    return false;
};





bool Fraction::operator<=(const Fraction &) const {
    return false;
};

bool Fraction::operator<=(float) const {
    return false;
};
bool operator<=(float, const Fraction &){
    return false;
};






Fraction Fraction::operator++(int) {
    return Fraction();
};

Fraction Fraction::operator--(int) {
    return Fraction();
};




Fraction Fraction::operator++() {
    return Fraction();
};

Fraction Fraction::operator--() {
    return Fraction();
};






int Fraction::gcd(int abc, int bcd) {
    return 0;
};

int Fraction::getUp() {
    return 0;
};








int Fraction::getDown() {
    return 0;
};

std::ostream &operator<<(std::ostream &output, const Fraction &other) {
    output << "" << "/" << "";
    return output;

};





