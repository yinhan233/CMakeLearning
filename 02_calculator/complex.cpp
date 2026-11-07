#include "complex.h"
#include <iostream>
#include <sstream>

complex::complex(double real,double imag):real(real),imag(imag){}
complex::~complex(){}

complex complex::operator+(const complex& other)const{
    return complex(real+other.real,imag+other.imag);
}
complex complex::operator-(const complex& other)const{
    return complex(real-other.real,imag-other.imag);
}
complex complex::operator*(const complex& other)const{
    return complex(real*other.real-imag*other.imag,real*other.imag+imag*other.real);
}
complex complex::operator/(const complex& other)const{
    const double denominator = other.real * other.real + other.imag * other.imag;
    if (denominator == 0.0) {
        std::cout << "输入错误：除数不能为0" << std::endl;
        return *this;
    }
    return complex(
        (real * other.real + imag * other.imag) / denominator,
        (imag * other.real - real * other.imag) / denominator
    );
}
void complex::print()const{
    std::cout<<real<<"+"<<imag<<"i"<<std::endl;
}

std::ostream & operator<<(std::ostream &os,const complex& c)
{
    if(c.real==0&&c.imag==0)
    {
        return os<<"0";
    }
    if(c.real)
    {
        os<<c.real;
    }
    if(c.imag<0)
    {
        os<<c.imag<<"i";
    }
    else if(c.imag>0)
    {
        os<<"+"<<c.imag<<"i";
    }
    return os;
}