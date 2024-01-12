#include <bits/stdc++.h>
using namespace std;
#include "Fraction.h"
#include "Int.h"
#include "Polynomial.h"

typedef Int_<int, 8> Int;
void passTests()
{
    cout << ":: PASS TESTS ::" << endl
         << endl;
    cout << "Object Creation : " << endl;
    vector<Fraction<Int> >f1;

    f1.push_back(Fraction<Int>(Int(1), Int(2)));
    f1.push_back(Fraction<Int>(Int(3), Int(4)));
    reverse(f1.begin(),f1.end());
    Poly<Fraction<Int>> p1(f1);
    cout << "p1 = " << p1 << endl;

    vector<Fraction<Int> >f2;

    f2.push_back(Fraction<Int>(Int(5), Int(6)));
    reverse(f2.begin(),f2.end());

    Poly<Fraction<Int>> p2(f2);
    cout << "p2 = " << p2 << endl;
    cout << endl
         << "Arithmatic Operations : " << endl;
    cout << "p1 + p2 = " << (p1 + p2) << endl;
    cout << "p1 - p2 = " << (p1 - p2) << endl;
    cout << endl
         << "Advanced Assignment Operations : " << endl;
    cout << "p1 = " << p1 << " & p2 = " << p2 << endl;
    cout << "p1 += p2;" << endl;
    p1 += p2;
    cout << "p1 = " << p1 << " & p2 = " << p2 << endl;
    cout << "p1 -= p2;" << endl;
    p1 -= p2;
    cout << "p1 = " << p1 << " & p2 = " << p2 << endl;
    cout << "Evaluation operation : " << endl;
    cout << "p1 = " << p1 << endl;
    cout << "p1(1/3) = " << p1(Fraction<Int>(Int(1), Int(3))) << endl;
    cout << endl;
}
void failTests()
{
    cout << ":: FAIL TESTS ::" << endl
         << endl;
    try
    {
        vector<Fraction<Int> >f1;

        f1.push_back(Fraction<Int>(Int(1), Int(0)));
        Poly<Fraction<Int>> p3(f1);
    }
    catch (const char *s)
    {
        cout << s << endl;
    }
}
int main()
{
    passTests();
    failTests();
    return 0;
}