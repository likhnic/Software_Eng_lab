#include <iostream>
#include "Fraction.h"
#include "Int.h"
#include "Polynomial.h"
using namespace std;

void PassTest()
{
    cout << ":::PASS TESTS:::" << endl
         << endl;
    Fraction<Int_<int, 4>> fia(3, -7);
    cout << "Fraction<Int_<int,4> >fia(3,-7) = " << fia << '\n';
    Fraction<Int_<int, 4>> fib(1, 5);
    cout << "Fraction<Int_<int,4> >fib(1,5) = " << fib << '\n';
    cout << "fia + fib = " << fia + fib << '\n';
    cout << "fia * fib = " << fia * fib << '\n';
    cout << "fia % fib = " << fia % fib << '\n';
}

void FailTest()
{
    cout << ":::FAIL TESTS:::" << endl
         << endl;
    cout << "Fraction<Int_<int,4> >fia(3,16) : ";
    try
    {
        Fraction<Int_<int, 4>> fia(3, 16);
    }
    catch (const char *s)
    {
        cout << s << '\n';
    }
    Fraction<Int_<int, 4>> fia(3, 15);
    Fraction<Int_<int, 4>> fib(16, 9);
    cout << "fia = " << fia << '\n';
    cout << "fib = " << fib << '\n';
    try
    {
        cout << "fia/fib = " << fia / fib << '\n';
    }
    catch (const char *s)
    {
        cout << s << '\n';
    }
}

void MixedTest()
{
    cout << ":::MIXED TESTS:::" << endl
         << endl;
    vector<Fraction<Int_<int, 4>>> v1, v2;

    // uncooment for generating random coefficients
    // for(int i=0;i<4;++i){
    //     Fraction<Int_<int,4> >fia(rand()%8,rand()%7+1);
    //     v1.push_back(fia);
    //     Fraction<Int_<int,4> >fib(rand()%8,rand()%7+1);
    //     v2.push_back(fib);
    // }

    // here we use easier numbers to calculate results and verify easily
    for (int i = 0; i < 4; ++i)
    {
        Fraction<Int_<int, 4>> fia(1, 1);
        v1.push_back(fia);
        Fraction<Int_<int, 4>> fib(1, 1);
        v2.push_back(fib);
    }
    Poly<Fraction<Int_<int, 4>>> pfia(v1);
    Poly<Fraction<Int_<int, 4>>> pfib(v2);
    cout << "pfia = " << pfia << '\n';
    cout << "pfib = " << pfib << '\n';
    try
    {
        cout << "pfia + pfib = " << pfia + pfib << '\n';
    }
    catch (const char *s)
    {
        cout << s << '\n';
        cout << "Since rand is used the denominator when two fractions are added can be zero\n";
    }
    Fraction<Int_<int, 4>> fia(1, 1);
    cout << "fia  = " << fia << '\n';
    cout << "pfia(fia) = " << pfia(fia) << '\n';

    vector<Int_<int, 4>> vpia;
    for (int i = 0; i < 5; ++i)
    {
        vpia.push_back(5 - i);
    }
    Poly<Int_<int, 4>> pia(vpia);
    cout << "pia = " << pia << '\n';
    cout << "pai(1) = " << pia(1) << '\n';
    // pai(1)==reduce(15)=-1;

    vector<Int_<int, 4>> vpib;
    for (int i = 0; i < 5; ++i)
    {
        vpib.push_back(25 - i * i + 1);
    }
    Poly<Int_<int, 4>> pib(vpib);
    cout << "pib = " << pib << '\n';
    cout << "pia + pib = " << pia + pib << '\n';
}

int main()
{
    srand(time(0));
    PassTest();
    FailTest();
    MixedTest();
}
