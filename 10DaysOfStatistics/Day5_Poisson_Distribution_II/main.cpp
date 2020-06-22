/*
The manager of a industrial plant is planning to buy a machine of either type A or type B. For each day’s operation:

The number of repairs, X, that machine A needs is a Poisson random variable with mean 0.88. The daily cost of operating A is C_A=160+40X^2.
The number of repairs, Y, that machine B needs is a Poisson random variable with mean 1.55. The daily cost of operating B is C_B=128+40Y^2.

Assume that the repairs take a negligible amount of time and the machines are maintained nightly to ensure that they operate like
new at the start of each day. Find and print the expected daily cost for each machine.

The probability distribution of a possion random variable (Poisson distribution) is:
P(k,lambda)=lambda^k * e^-lambda / k!

E[X^2] = lambda^2 + lamda

The expected cost of operaation is E[C]=fixed_cost+cost_per_fix*E[lambda^2] = fixed_cost+cost_per_fix*[Lambda^2+lambda]

*/

#include <iostream>
#include <cmath>
#include <array>

float Ecost(const int b, const int m, float lambda)
{
    return b + m*(pow(lambda,2) + lambda) ;
}

int main()
{
    /// Hard coded (for testing).
    //std::array<const float,2> lambda{0.88,1.55} ; // Average number of daily repairs for machine A and B.

    /// Machine costs.
    const int fixed_cost_A = 160 ;   // Y-intercept.
    const int fixed_cost_B = 128 ;   // Y-intercept.
    const int price_per_fix = 40 ;   // Slope.

    /// Read input from STDIN.
    const int number_machines = 2 ;
    std::array<float,number_machines> lambda ; // Average number of fixes for a given mahcine.

    std::size_t ii = 0 ;
    while (ii < lambda.size())
    { // For reading space separated values.
        std::cin >> lambda[ii++] ;
    }

    /// Expected cost of operation E[X]
    printf("%.3f\n",Ecost(fixed_cost_A, price_per_fix, lambda[0])) ;
    printf("%.3f",Ecost(fixed_cost_B, price_per_fix, lambda[1])) ;

    return 0 ;
}
