#include <bits/stdc++.h>
using namespace std;

template <class T>
T Max(T a, T b)
{
    if (a > b)
        return a;
    return b;
}

template <class T>
T Min(T a, T b)
{
    if (a < b)
        return a;
    return b;
}

template <typename T = int>
class Poly
{
    vector<T> coeff_;
    size_t deg_;

public:
    // constructor
    Poly(vector<T> coeff = vector<T>(1,T(1))) : deg_(coeff.size())
    {
        coeff_ = coeff;
        if(deg_==1){
            if(coeff[0]==T(0)){
                throw "Zero is not a Polynomial";
            }
        }
    }

    Poly<T> &operator=(const Poly<T> &p)
    {
        if (this != &p)
        {
            coeff_ = p.coeff_;
            deg_ = p.deg_;
        }
        return *this;
    }

    /*------------Unary operators--------------*/

    Poly<T> operator+()
    {
        Poly newP = *this;
        return newP;
    }

    Poly<T> operator-()
    {
        Poly newP = *this;
        for (int i = 0; i < int(this->deg_); ++i)
        {
            newP.coeff_[i] = -newP.coeff_[i];
        }
        return newP;
    }

    /*------------Binary operators--------------*/

    Poly<T> operator+(const Poly<T> &p)
    {
        Poly newP;
        newP.coeff_.clear();
        // come from last, add till both have their coeff's
        // else pushback the left indices of the remaining polynomial coefficients
        if (deg_ > p.deg_)
        {
            newP.deg_ = deg_;
            int i = deg_ - 1, j = p.deg_ - 1;
            while (j != -1)
            {
                newP.coeff_.push_back(coeff_[i] + p.coeff_[j]);
                i--;
                j--;
            }
            while (i != -1)
            {
                newP.coeff_.push_back(coeff_[i]);
                i--;
            }
        }
        else
        {
            newP.deg_ = deg_;
            int i = deg_ - 1, j = p.deg_ - 1;
            while (i != -1)
            {
                newP.coeff_.push_back(coeff_[i] + p.coeff_[j]);
                i--;
                j--;
            }
            while (j != -1)
            {
                newP.coeff_.push_back(const_cast<T&>(p.coeff_[j]));
                j--;
            }
        }
        newP.deg_ = newP.coeff_.size();
        reverse(newP.coeff_.begin(), newP.coeff_.end());
        return newP;
    }

    Poly<T> operator-(const Poly<T> &p)
    {
        // come from last, subtract till both have their coeff's
        // else pushback the left indices of the remaining polynomial coefficients
        Poly newP;
        newP.coeff_.clear();
        if (deg_ > p.deg_)
        {
            newP.deg_ = deg_;
            int i = deg_ - 1, j = p.deg_ - 1;
            while (j != -1)
            {
                newP.coeff_.push_back(coeff_[i] - p.coeff_[j]);
                i--;
                j--;
            }
            while (i != -1)
            {
                newP.coeff_.push_back(coeff_[i]);
                i--;
            }
        }
        else
        {
            newP.deg_ = deg_;
            int i = deg_ - 1, j = p.deg_ - 1;
            while (i != -1)
            {
                newP.coeff_.push_back(coeff_[i] - p.coeff_[j]);
                i--;
                j--;
            }
            while (j != -1)
            {
                newP.coeff_.push_back(-const_cast<T&>(p.coeff_[j]));
                j--;
            }
        }
        newP.deg_ = newP.coeff_.size();
        reverse(newP.coeff_.begin(), newP.coeff_.end());
        return newP;
    }

    /*------------Advanced Binary operators--------------*/

    Poly<T> &operator+=(const Poly<T> &p)
    {
        (*this) = (*this) + p;
        return *this;
    }

    Poly<T> &operator-=(const Poly<T> &p)
    {
        (*this) = (*this) - p;
        return *this;
    }

    T operator()(T x)
    {
        T power(1);
        T sum(0);
        for (int i = deg_ - 1; i >= 0; --i)
        {
            sum += (coeff_[i] * power);
            power *= x;
        }
        return sum;
    }

    /*-----------------Input/Output-----------------*/

    friend ostream &operator<<(ostream &os, const Poly<T> &p)
    {
        for (int i = 0; i < int(p.deg_); ++i)
        {
            os << "(" << p.coeff_[i] << ")x^" << p.deg_ - i - 1;
            if (i != int(p.deg_ - 1))
                os << "+";
        }
        return os;
    }

    friend istream &operator>>(istream &is, Poly<T> &f)
    {
        size_t deg;
        is >> deg;
        f.coeff_.clear();
        for (int i = 0; i < int(deg); ++i)
        {
            T x;
            is >> x;
            f.coeff_.push_back(x);
        }
        return is;
    }
};
