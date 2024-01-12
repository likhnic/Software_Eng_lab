#include <iostream>
#include "Fraction.h"
using namespace std;

typedef Fraction<int> Fraction_;

void PassTest()
{
    cout << ":::PASS TESTS:::" << endl
         << endl;
    Fraction_ fa(5, -3);
    cout << "Fraction_ fa(5, 3) = " << fa << endl;
    Fraction_ fb(7, 9);
    cout << "Fraction_ fb(7, 9) = " << fb << endl;
    cout << "fa + fb = " << (fa + fb) << endl;
    cout<<"fa after converting to double = "<<fa.convertToDouble()<<'\n';
}
void FailTest()
{
    cout << ":::FAIL TESTS:::" << endl
         << endl;
    try
    {
        cout << "Fraction_(1, 0): ";
        Fraction_ f1(1, 0);
    }
    catch (const char *s)
    {
        cout << s << endl;
    }
    Fraction_ f1(5, 12), f2(0, 1), f3;
    try
    {
        cout << "Binary Divide: f3 = " << f1 << " / " << f2 << ": ";
        f3 = f1 / f2;

        cout << f3 << endl;
    }
    catch (const char *s)
    {
        cout << s << endl;
    }
}
void MixedTest()
{
    cout << ":::MIXED TESTS:::" << endl
         << endl;
    Fraction_ f1(2, 3), f2(8), f3(5, 6), f4;
    cout << "f1 = " << f1 << " f2 = " << f2 << " f3 = " << f3 << " f4 = " << f4 << endl;
    // f1 = 2/3 f2 = 8 f3 = 5/6 f4 = 1
    f4 = (f1 + f2) / (f1 - f2) + !f3 - f2 * f3;
    cout << "f4 = (f1 + f2) / (f1 - f2) + !f3 - f2 * f3 = " << f4 << endl;
    // f4 = (f1 + f2) / (f1 - f2) + !f3 - f2 * f3 = -1097/165
    cout << "f4 + 5 = " << f4 + 5 << '\n';
}

int main()
{
    PassTest();
    FailTest();
    MixedTest();
}