#include <iostream>
#include "Polynomial.h"
using namespace std;

typedef Poly<int> Poly_;

void PassTest()
{
    cout << ":::PASS TESTS:::" << endl
         << endl;
    Poly_ pa(vector<int>(3, 5)); // vector with size=3, and all values as 5
    cout << "pa = " << pa << '\n';
    vector<int> temp;
    for (int i = 0; i < 7; ++i)
    {
        temp.push_back((rand() % 30 - 15));
    }
    Poly_ pb(temp); // vector with size=7 , ranndom integers filled
    cout << "pb = " << pb << '\n';
    cout << "pa + pb = " << pa + pb << '\n';
}

void FailTest()
{
    cout << ":::FAIL TESTS:::" << endl
         << endl;
    cout << "No fail cases\n";
}

void MixedTest()
{
    cout << ":::MIXED TESTS:::" << endl
         << endl;
    Poly_ pa(vector<int>(3, 5)); // vector with size=3, and all values as 5
    cout << "pa = " << pa << " pa(4) = " << pa(4) << '\n';
    vector<int> temp;
    for (int i = 0; i < 7; ++i)
    {
        temp.push_back((rand() % 30 - 15));
    }
    Poly_ pb(temp); // vector with size=7 , ranndom integers filled
    cout << "pb = " << pb << '\n';
    cout << "pa(pb(1)) = " << pa(pb(1)) << '\n';
    temp.clear();
    for (int i = 0; i < 9; ++i)
    {
        temp.push_back((rand() % 8 - 4));
    }
    Poly_ pc(temp); // vector with size=9 , ranndom integers filled
    cout << "pc  = " << pc << '\n';
    cout << "-pa+pb-pc = " << -pa + pb - pc << '\n';
}

int main()
{
    srand(time(0));
    PassTest();
    FailTest();
    MixedTest();
}
