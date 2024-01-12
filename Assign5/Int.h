#include <iostream>
using namespace std;

template <typename T = int, unsigned int N = 4>
class Int_
{
    T v_;

    // Utility function to get the values in [MinInt,MaxInt]
    void reduce(Int_<T, N> &In)
    {
        // if the value is >MaxInt then come back to MinInt side and then increment
        // else other side
        // this can be simulated using modulo of space between MaxInt and MinInt
        if (In.v_ > MaxInt.v_)
        {
            In.v_ = (In.v_ - MinInt.v_) % (MaxInt.v_ - MinInt.v_ + 1) + MinInt.v_;
        }
        if (In.v_ < MinInt.v_)
        {
            In.v_ = (In.v_ - MaxInt.v_) % (MaxInt.v_ - MinInt.v_ + 1) + MaxInt.v_;
        }
    }

public:
    // These are in public because user may want to use them in some boundaries
    static const Int_<T, N> MaxInt;
    static const Int_<T, N> MinInt;

    // constructor
    Int_(T a = 0) : v_(a)
    {
        reduce(*this);
    };

    // unary operation
    Int_<T, N> operator-()
    {
        Int_<T, N> newInt;
        if (-v_ != MinInt.v_)
        {
            newInt.v_ = -v_;
        }
        else
            newInt.v_ = v_;
        return newInt;
    }

    /*------------Binary operators--------------*/
    // add 2 int's
    Int_<T, N> operator+(const Int_<T, N> &In)
    {
        Int_<T, N> newInt;
        newInt.v_ = v_ + In.v_;
        reduce(newInt);
        return newInt;
    }

    Int_<T, N> operator-(const Int_<T, N> &In)
    {
        Int_<T, N> newInt;
        newInt = *this + (-(const_cast<Int_<T, N> &>(In)));
        return newInt;
    }

    Int_<T, N> operator*(const Int_<T, N> &In)
    {
        Int_<T, N> newInt;
        newInt.v_ = v_ * In.v_;
        reduce(newInt);
        return newInt;
    }

    Int_<T, N> operator/(const Int_<T, N> &In)
    {
        Int_<T, N> newInt;
        if (In.v_ == 0)
            throw "Denominator can't be Zero!";
        newInt.v_ = v_ / In.v_;
        reduce(newInt);
        return newInt;
    }

    Int_<T, N> operator%(const Int_<T, N> &In)
    {
        Int_<T, N> newInt;
        if (In.v_ == 0)
            throw "Denominator can't be Zero!";
        newInt.v_ = v_ % In.v_;
        reduce(newInt);
        return newInt;
    }

    /*------------Increment/Decrement operators--------------*/
    Int_<T, N> &operator++()
    {
        Int_ newInt = 1;
        *this = *this + newInt;
        reduce(*this);
        return *this;
    }

    Int_<T, N> &operator--()
    {
        Int_ newInt = 1;
        *this = *this - newInt;
        reduce(*this);
        return *this;
    }

    Int_<T, N> operator++(int)
    {
        Int_ newInt = 1, copy = *this;
        *this = *this + newInt;
        reduce(*this);
        return copy;
    }

    Int_<T, N> operator--(int)
    {
        Int_ newInt = 1, copy = *this;
        *this = (*this) - newInt;
        reduce(*this);
        return copy;
    }

    /*------------Advanced Binary operators--------------*/

    Int_<T, N> &operator+=(const Int_<T, N> &In)
    {
        *this = (*this) + In;
        return *this;
    }

    Int_<T, N> &operator-=(const Int_<T, N> &In)
    {
        *this = (*this) - In;
        return *this;
    }

    Int_<T, N> &operator*=(const Int_<T, N> &In)
    {
        *this = (*this) * In;
        return *this;
    }

    Int_<T, N> &operator/=(const Int_<T, N> &In)
    {
        try
        {
            *this = (*this) / In;
        }
        catch (const char *s)
        {
            throw s;
        }
        return *this;
    }

    Int_<T, N> &operator%=(const Int_<T, N> &In)
    {
        try
        {
            *this = (*this) % In;
        }
        catch (const char *s)
        {
            throw s;
        }
        return *this;
    }

    /*------------Logical operators--------------*/

    bool operator==(const Int_<T, N> &In)
    {
        if (this->v_ == In.v_)
            return true;
        return false;
    }

    bool operator>(const Int_<T, N> &In)
    {
        if (this->v_ > In.v_)
            return true;
        return false;
    }

    bool operator<(const Int_<T, N> &In)
    {
        if (this->v_ < In.v_)
            return true;
        return false;
    }

    bool operator>=(const Int_<T, N> &In)
    {
        if (this->v_ >= In.v_)
            return true;
        return false;
    }

    bool operator<=(const Int_<T, N> &In)
    {
        if (this->v_ <= In.v_)
            return true;
        return false;
    }

    bool operator!=(const Int_<T, N> &In)
    {
        if (this->v_ != In.v_)
            return true;
        return false;
    }

    /*-----------------Input/Output--------------------*/

    friend ostream &operator<<(ostream &os, const Int_<T, N> &In)
    {
        os << In.v_;
        return os;
    }

    friend istream &operator>>(istream &is, Int_<T, N> &In)
    {
        T x;
        is >> x;
        In.v_ = x;
        In.reduce(In);
        return is;
    }
};

/*---Static varaibles of class template initialsed here----*/

template <typename T, unsigned int N>
const Int_<T, N> Int_<T, N>::MaxInt = (1 << (N - 1)) - 1;

template <typename T, unsigned int N>
const Int_<T, N> Int_<T, N>::MinInt = -(1 << (N - 1));
