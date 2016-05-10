#include "multiple_integral.h"


multiple_integral::multiple_integral()
{

}

long double multiple_integral::back_func(long double x, long double y,double tau)
{
    if (x == M_PI_2 && y == 0)
        return cos(x)*sin(x);


    return (1 - exp(-tau * (2.*cos(x))/(1 - sin(x)*sin(x)*cos(y)*cos(y))))*cos(x)*sin(x);
}

double multiple_integral::Integral_cell(double a, double b, unsigned int teta_count, double c, double d, unsigned int phi_count, double tau)
{
    double d_phi = (d-c)/phi_count;
    double d_teta = (b-a)/teta_count;

    double dd_phi = d_phi/2.;
    double dd_teta = d_teta/2.;

    long double integ = 0;


    for(double phi = a ; phi<=b-dd_phi ; phi+=d_phi )
    {
        for(double teta = c ; teta<=d-dd_teta ; teta+=d_teta )
            integ+= back_func(teta+dd_teta,phi+dd_phi,tau);

    }

    return integ*d_phi*d_teta;
}

long double multiple_integral::Integral_suc(double a, double b, unsigned int teta_count, double c, double d, unsigned int phi_count, double tau)
{
    long double d_phi = (d-c)/(2.*phi_count);
    long double d_teta = (b-a)/(2.*teta_count);

    long double sum = 0;

    long double f_a = 0;
    for(long double teta = a; teta<=b-2.*d_teta; teta+=2.*d_teta)
        f_a += d_teta/3. * (back_func(teta,c,tau) + 4. * back_func(teta+d_teta,c,tau) + back_func(teta+2.*d_teta,c,tau));

    for(long double phi = c; phi<=d-2.*d_phi; phi+=2.*d_phi)
    {

        long double f_b = 0;
        for(long double teta = a; teta<=b-2.*d_teta; teta+=2.*d_teta)
            f_b += d_teta/3. * (back_func(teta,phi+2.*d_phi,tau) + 4. * back_func(teta+d_teta,phi+2.*d_phi,tau) + back_func(teta+2.*d_teta,phi+2.*d_phi,tau));
        sum += (f_a+f_b)*d_phi;
        f_a = f_b;
    }

    return sum;
}

