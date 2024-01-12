#include <bits/stdc++.h>
using namespace std;
#include "Int.h"
#include "Fraction.h"
typedef Int_<int, 4> Int;
void passTests()
{
    cout << ":::PASS TESTS:::" << endl
         << endl;
    cout << "Object Creation : " << endl;
    Fraction<Int> fa(Int(5), Int(3));
    cout << "Fraction fa(5, 3) = " << fa << endl;
    Fraction<Int> fb(Int(7), Int(9));
    cout << "Fraction fb(7, 9) = " << fb << endl;
    cout << endl
         << "Arithmatic Operations : " << endl;
    cout << "fa + fb = " << (fa + fb) << endl;
    cout << "fa - fb = " << (fa - fb) << endl;
    cout << "fa * fb = " << (fa * fb) << endl;
    cout << "fa / fb = " << (fa / fb) << endl;
    cout << "fa % fb = " << (fa % fb) << endl;
    cout << endl
         << "Advanced Assignment Operation : " << endl;
    cout << "fa = " << fa << " fb = " << fb << endl;
    cout << "fa += fb;" << endl;
    fa += fb;
    cout << "fa = " << fa << " fb = " << fb << endl;
    cout << "fa -= fb;" << endl;
    fa -= fb;
    cout << "fa = " << fa << " fb = " << fb << endl;
    cout << "fa *= fb;" << endl;
    fa *= fb;
    cout << "fa = " << fa << " fb = " << fb << endl;
    cout << "fa /= fb;" << endl;
    fa /= fb;
    cout << "fa = " << fa << " fb = " << fb << endl;
    cout << "fa %= fb;" << endl;
    fa %= fb;
    cout << "fa = " << fa << " fb = " << fb << endl;
    cout << endl
         << "Relational Operations : " << endl;
    cout << "fa < fb = " << (fa < fb) << endl;
    cout << "fa <= fb = " << (fa <= fb) << endl;
    cout << "fa > fb = " << (fa > fb) << endl;
    cout << "fa >= fb = " << (fa >= fb) << endl;
    cout << "fa == fb = " << (fa == fb) << endl;
    cout << "fa != fb = " << (fa != fb) << endl;
    cout << endl
         << "Other operations : " << endl;
    cout << "fa = " << fa << endl;
    cout << "++fa = " << (++fa) << endl;
    cout << "--fa = " << (--fa) << endl;
    cout << "!fa = " << (!fa) << endl;
    cout << endl;
}
void failTests()
{
    cout << ":::FAIL TESTS:::" << endl
         << endl;
    try
    {
        cout << "Fraction(1, 0): ";
        Fraction<Int> f1(Int(1), Int(0));
    }
    catch (const char *s)
    {
        cout << s << endl;
    }
    Fraction<Int> f1(Int(5), Int(12)), f2(Int(0), Int(1)), f3;
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
    Fraction<Int> f0(Int(0), Int(4));
    try
    {
        cout << "f0 = " << f0 << endl;
        cout << "!f0 = " << (!f0) << endl;
    }
    catch (const char *s)
    {
        cout << s << endl;
    }
    cout << endl;
}
void MixedTest()
{
    cout << ":::MIXED TESTS:::" << endl
         << endl;
    Fraction<Int> f1(Int(2), Int(3)), f2(Int(8)), f3(Int(5), Int(6)), f4;
    cout << "f1 = " << f1 << " f2 = " << f2 << " f3 = " << f3 << " f4 = " << f4 << endl;
    f4 = (f1 + f2) / (f1 - f2) + !f3 - f2 * f3;
    cout << "f4 = (f1 + f2) / (f1 - f2) + !f3 - f2 * f3 = " << f4 << endl;
}
int main()
{
    passTests();
    failTests();
    MixedTest();
    return 0;
}