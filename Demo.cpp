/**
 * Demo file for the exercise on binary tree
 *
 * @author Evgeny Hershkovitch Neiterman
 * @since 2023-03
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <limits>
#include "sources/Fraction.hpp"
using namespace std;



using namespace ariel;


int main() {
//    Fraction a(4,5), b(14,21);
//    cout << "a: " << a << "b: " << b << endl;
//    cout << "a+b" << a+b << endl;
//    Fraction e(0.4);
//    cout << "e " << e.getNumerator() << endl;
//    cout << "e " << e-a << endl;
//    Fraction d(4, 5);
//    float e = 0.4;
//    Fraction g = e - d; // 2/5 - 4/5 = -2/5
//    cout << "e " << g.getNumerator() << endl;
//    cout << "e " << g.getDenominator() << endl;
//    cout << "a-b" << a-b << endl;
//    cout << "a/b" << a/b << endl;
//    cout << "a*b" << a*b << endl;
//    cout << "2.3*b" << 2.3*b << endl;
//    cout << "a+2.421" << a+2.421 << endl;
//    Fraction c = a+b-1;
//    cout << c++ << endl;
//    cout << --c << endl;
//    cout << "c >=b ? : " << (c >= b) << endl;
//    if (a > 1.1) cout << " a is bigger than 1.1" << endl;
//    else cout << " a is smaller than 1.1" << endl;
    int max_int = std::numeric_limits<int>::max();
    int min_int = std::numeric_limits<int>::min();
    Fraction f7(min_int + 1, 1);
    Fraction f5(max_int-1, 1);
    Fraction f6(min_int,1);
    cout<<f5.getNumerator()<<endl;
    cout<<f5.getDenominator()<<endl;
    cout<<f5.getDenominator()<<endl;

//    cout<<f7.getNumerator()<<"/"<<f7.getDenominator()<<endl;



}
