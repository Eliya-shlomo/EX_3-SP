//
// Created by eliya on 17/04/2023.
//

#include "doctest.h"
#include "sources/Fraction.hpp"
using namespace ariel;


TEST_CASE("constractor is initialized"){
    CHECK_NOTHROW(Fraction(1,1));
    CHECK_NOTHROW(Fraction(2,2));
    CHECK_NOTHROW(Fraction(4,4));
}

TEST_CASE("checking the correctness of the class implementing constructors"){
    Fraction f(4,5);
    CHECK(f==4/5);
    CHECK(f==0.8);
    f++;
    CHECK(f==9/5);
    CHECK(f==1.8);
}
TEST_CASE("checking the correctness of the class functions") {
    Fraction f(4,5);
    Fraction r(4,5);
    CHECK(f-r==0);
    CHECK(f+r==8/5);
    CHECK(f*r==16/25);
    CHECK(f/r==1/1);
    CHECK(f>=r);
    CHECK(f<=r);
    CHECK_FALSE(f>r);
    CHECK_FALSE(f<r);
}

TEST_CASE("checking correctness of constructors and functions after changing"){
    Fraction f(4,5);
    Fraction r(4,5);
    f++;
    CHECK(f>r);
    f--;
    CHECK(f==r);
    r++;
    CHECK(f<r);
}

TEST_CASE("checking correctness with third constructor involved "){
    Fraction f(4,5);
    Fraction r(4,5);
    Fraction a =f*r;
    CHECK(f.getDown()<a.getDown());
    a=f/r;
    CHECK(a.getUp()==1);
};