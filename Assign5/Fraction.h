#include <iostream>
using namespace std;

// template function to swap
template <class T>
void Swap(T &x, T &y)
{
    T temp;
    temp = x;
    x = y;
    y = temp;
}

// template function to find GCD using Euclidean method
template <class T>
T gcd(T x, T y)
{
    if (x < y)
        Swap<T>(x, y);
    while (1)
    {
        x %= y;
        if (x == 0)
            break;
        Swap(x, y);
    }
    return y;
}

// template function to find LCM using product of LCM and GCD of two numbers is the product of the two numbers
template <class T>
T lcm(T x, T y)
{
    return x * y / gcd(x, y);
}

template <typename T = int>
class Fraction
{
    T n_;
    T d_;
    void reduce()
    {
        if (d_ == 0)
        {
            throw "Denominator can't be Zero!";
        }
        if (d_ < 0)
        {
            n_ = -n_;
            d_ = -d_;
        }
        if (n_ == 0)
            d_ = 1;
        else
        {
            T GCD;
            if (n_ < 0)
                GCD = gcd(-n_, d_);
            else
                GCD = gcd(n_, d_);

            n_ /= GCD;
            d_ /= GCD;
        }
    }

public:
    // Constructor
    Fraction(T n = 1, T d = 1) : n_(n), d_(d)
    {
        if (d == 0)
            throw "Denominator can't be zero";
        try
        {
            reduce();
        }
        catch (const char *s)
        {
            throw s;
        }
    }
    // copy operator
    Fraction(const Fraction<T> &f)
    {
        n_ = f.n_;
        d_ = f.d_;
    }

    /*------------Unary operators--------------*/

    // pre increment, componendo
    const Fraction<T> &operator++()
    {
        n_ += d_;
        reduce();
        return *this;
    }
    // pre decrement, dividendo
    const Fraction<T> &operator--()
    {
        n_ -= d_;
        reduce();
        return *this;
    }

    // assignment operator
    Fraction<T> &operator=(const Fraction<T> &f)
    {
        if (this != &f)
        {
            n_ = f.n_;
            d_ = f.d_;
        }
        return *this;
    }

    Fraction<T> operator+()
    {
        Fraction<T> newF(n_, d_);
        return newF;
    }

    // negetion operator
    Fraction<T> operator-()
    {
        Fraction<T> newF(-n_, d_);
        return newF;
    }
    // add two fractions
    friend Fraction<T> operator+(const Fraction<T> &f1, const Fraction<T> &f2)
    {
        T LCM = lcm(f1.d_, f2.d_);
        T num = const_cast<T &>(f1.n_) * (LCM / f1.d_) + const_cast<T &>(f2.n_) * (LCM / f2.d_);
        T denom = LCM;
        Fraction newFraction(num, denom);
        return newFraction;
    }
    // subtract two fractions(overloading the negetion operator)
    friend Fraction<T> operator-(const Fraction<T> &f1, const Fraction<T> &f2)
    {
        T LCM = lcm(f1.d_, f2.d_);
        T num = const_cast<T &>(f1.n_) * (LCM / f1.d_) - const_cast<T &>(f2.n_) * (LCM / f2.d_);
        T denom = LCM;
        Fraction newFraction(num, denom);
        return newFraction;
    }
    // multiplication of two fractions
    friend Fraction<T> operator*(const Fraction<T> &f1, const Fraction<T> &f2)
    {
        T num = const_cast<T &>(f1.n_) * const_cast<T &>(f2.n_);
        T denom = const_cast<T &>(f1.d_) * const_cast<T &>(f2.d_);
        Fraction newFraction(num, denom);
        return newFraction;
    }

    // division of two fractions
    friend Fraction<T> operator/(const Fraction<T> &f1, const Fraction<T> &f2)
    {
        T num = const_cast<T &>(f1.n_) * const_cast<T &>(f2.d_);
        T denom = const_cast<T &>(f1.d_) * const_cast<T &>(f2.n_);
        Fraction newFraction(num, denom);
        return newFraction;
    }
    // modulo of two fractions, overloading modulo operator
    friend Fraction<T> operator%(const Fraction<T> &f1, const Fraction<T> &f2)
    {
        Fraction newF = f1 / f2;
        Fraction newF2(newF.n_ / newF.d_, 1);
        Fraction newF3 = newF2 * f2;
        return f1 - newF3;
    }
    /*------------Advanced Asignment Operators-----------------*/

    Fraction<T> &operator+=(const Fraction<T> &f2)
    {
        *this = *this + f2;
        return *this;
    }

    Fraction<T> &operator-=(const Fraction<T> &f2)
    {
        *this = *this - f2;
        return *this;
    }

    Fraction<T> &operator*=(const Fraction<T> &f2)
    {
        *this = *this * f2;
        return *this;
    }

    Fraction<T> &operator/=(const Fraction<T> &f2)
    {
        *this = *this / f2;
        return *this;
    }

    Fraction<T> &operator%=(const Fraction<T> &f2)
    {
        *this = *this % f2;
        return *this;
    }

    /*------------Binary Relational operators--------------*/

    // less than op
    bool operator<(const Fraction<T> &f)
    {
        Fraction newF = *this - f;
        if (newF.n_ < 0)
            return true;
        return false;
    }

    // greater than op
    bool operator>(const Fraction<T> &f)
    {
        Fraction newF = *this - f;
        if (newF.n_ > 0)
            return true;
        return false;
    }

    // less than or equal to op
    bool operator<=(const Fraction<T> &f)
    {
        Fraction newF = *this - f;
        if (newF.n_ <= 0)
            return true;
        return false;
    }

    bool operator>=(const Fraction<T> &f)
    {
        Fraction newF = *this - f;
        if (newF.n_ >= 0)
            return true;
        return false;
    }

    bool operator==(const Fraction<T> &f)
    {
        Fraction newF = *this - f;
        if (newF.n_ == 0)
            return true;
        return false;
    }

    bool operator!=(const Fraction<T> &f)
    {
        Fraction newF = *this - f;
        if (newF.n_ != 0)
            return true;
        return false;
    }

    friend ostream &operator<<(ostream &os, const Fraction<T> &f)
    {
        os << f.n_ << "/" << f.d_;
        return os;
    }

    friend istream &operator>>(std::istream &is, Fraction<T> &f)
    {
        T a, b;
        is >> a >> b;
        f = {a, b};
        return is;
    }

    /*----Extended operations - Convert to Double---*/

    double convertToDouble(){
        return double(n_)/d_;
    }

    // Invert the fraction
    const Fraction<T> &operator!()
    {
        Swap(n_, d_);
        reduce();
        return *this;
    }
};