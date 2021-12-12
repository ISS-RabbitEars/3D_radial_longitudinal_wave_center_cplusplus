#ifndef vec_hpp
#define vec_hpp
#include <iostream>
#include <cmath>
using namespace std;

class vec
{
public:
    
    double x,y,z;
    vec();
    ~vec();
    vec(const double, const double, const double);
    vec(const double, const double);
    vec(const double);
    vec& operator() (const double, const double, const double);
    vec& operator() (const double, const double);
    vec& operator() (const double);
    vec& operator() ();
    double norm();
    vec hat();
    vec operator+(const vec&)const;
    vec operator-(const vec&)const;
    vec operator*(const double&)const;
    friend vec operator*(const double&, const vec&);
    vec& operator+=(const vec&);
    vec& operator-=(const vec&);
};


#include "vec.cpp"
#endif
