/*
You have a sample of 100 values from a population with mean mu=500 and with standard deviation sigma=80.
Compute the interval that covers the middle 95% of the distribution of the sample mean; in other words,
compute A and B such that P(A<X<B)=95. Use a z-score of z=1.96.

A = mu-(z*sigma/sqrt(n))
B = mu+(z*sigma/sqrt(n))
*/

#include <iostream>
#include <cmath>

double f(double sigma, double n, double z)
{
    return z*sigma/std::sqrt(n) ;
}

int main()
{
    // Inputs.
    double n, mu, sigma, interval, z ;
    std::cin >> n ;
    std::cin >> mu ;
    std::cin >> sigma ;
    std::cin >> interval ;
    std::cin >> z ;

    // Interval.
    printf("%.2f\n", mu - f(sigma,n,z)) ;
    printf("%.2f", mu + f(sigma,n,z)) ;

    return 0 ;
}
