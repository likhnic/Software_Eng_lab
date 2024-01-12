#include <iostream>
#include "Int.h"
using namespace std;

typedef Int_<int, 4> Int;

void PassTest()
{
    cout << ":::PASS TESTS:::" << endl
         << endl;
    Int ia(3);
    cout << "Int ia(3) is " << ia << '\n';
    Int ib(17);
    cout << "Int ib(17) is " << ib << '\n';
    Int ic(-55);
    cout << "Int ic(-55) is " << ic << '\n';
    cout << "ia+ib = " << ia + ib << '\n';
    cout << "ib-ic = " << ib - ic << '\n';
    cout << "ia*ic = " << ia * ic << '\n';
    cout << "ia<ib is (0-false, 1-true) : " << (ia < ib) << '\n'
         << '\n';
}

void FailTest()
{
    cout << ":::FAIL TESTS:::" << endl
         << endl;
    Int ia(3);
    Int ib(16);
    cout << "Int ia(3) is " << ia << '\n';
    cout << "Int ib(16) is " << ib << '\n';
    cout << "ia/ib = ";
    try
    {
        cout << ia / ib << '\n';
    }
    catch (const char *s)
    {
        cout << s << '\n';
    }
    cout << "ia%ib = ";
    try
    {
        cout << ia % ib << '\n';
    }
    catch (const char *s)
    {
        cout << s << '\n';
    }
    cout << '\n';
}

void MixedTest()
{
    cout << ":::MIXED TESTS:::" << endl
         << endl;
    Int ia, ib(19), ic(-7), id(37), ie(56);
    cout << "ia = " << ia << " ib = " << ib << " ic = " << ic << " id = " << id << " ie = " << ie << '\n';
    cout << "ia + ib * ic / id % ie = " << ia + ib * ic / id % ie << '\n';
    // ia + ib * ic / id % ie = -1
    cout << '\n';
}

int main()
{
    PassTest();
    FailTest();
    MixedTest();
}