#include <bits/stdc++.h>
using namespace std;
#include "Int.h"
#include "Polynomial.h"
typedef Int_<int, 4> Int;
void passTests()
{
    cout << ":: PASS TESTS ::" << endl
         << endl;
    cout << "Object Creation : " << endl;

    vector<Int>v1;
    v1.push_back(Int(1));
    v1.push_back(Int(2));
    v1.push_back(Int(3));
    Poly<Int> p1(v1);
    cout << "p1 = " << p1 << endl;

    vector<Int>v2;
    v2.push_back(Int(4));
    v2.push_back(Int(5));
    v2.push_back(Int(6));
    v2.push_back(Int(7));
    Poly<Int> p2(v2);
    
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
    cout << "p2 = " << p2 << endl;
    cout << "p2(2) = " << p2(2) << endl;
    cout << endl;
}
void failTests()
{
    cout << ":: FAIL TESTS ::" << endl
         << endl;

    try
    {
        vector<int>v;
        v.push_back(0);
        Poly<int> p2(v);
        cout << "p2 = " << p2 << endl;
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