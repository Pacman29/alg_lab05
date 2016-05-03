#ifndef MULTIPLE_INTEGRAL_H
#define MULTIPLE_INTEGRAL_H
#include "cmath"

class multiple_integral
{
public:
    multiple_integral();
    long double back_func(long double x, long double y, double tau);
    double Integral_cell(double a, double b, unsigned int teta_count, double c, double d, unsigned int phi_count, double tau);
    long double Integral_suc(double a, double b, unsigned int teta_count, double c, double d, unsigned int phi_count, double tau);
};

#endif // MULTIPLE_INTEGRAL_H
