/*
A random variable, X, follows Poisson distribution with mean of 2.5.
Find the probability with which the random variable X is equal to 5.

The probability distribution of a possion random variable (Poisson distribution) is:
P(k,lambda)=lambda^k * e^-lambda / k!

*/

#include <iostream>
#include <cmath>

int fact(int n)
{
    if (n == 0) return 1 ;
    return n * fact(n-1) ;
}

float poisson(const int k, const float lambda)
{
    return pow(lambda,k) * exp(-lambda) / fact(k) ;
}

int main()
{
    /// Hard coded (for testing).
    // const float lambda = 2.5 ;
    // const int k  = 5 ;

    /// Read input from STDIN.
    float lambda;
    std::cin >> lambda ;

    int k ;
    std::cin >> k ;

    /// Print output to STDOUT.
    printf("%.3f",poisson(k,lambda)) ;

    return 0 ;
}
