#ifndef COMPLEX_H
#define COMPLEX_H

#include <ostream>

class complex
{
private:
    double real;
    double imag;
public:
    complex(double real, double imag);
    complex operator+(const complex& other) const;
    complex operator-(const complex& other) const;
    complex operator*(const complex& other) const;
    complex operator/(const complex& other) const;
    void print() const;
    friend std::ostream& operator<<(std::ostream& os, const complex& c);
    ~complex();
};

#endif
