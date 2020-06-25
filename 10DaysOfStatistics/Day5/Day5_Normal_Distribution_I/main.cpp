/*
In a certain plant, the time taken to assemble a car is a random variable, X,
having a normal distribution with a mean of 20 hours and a standard deviation of 2 hours.

What is the probability that a car can be assembled at this plant in:
1) Less than 19 hours?

2) Between 20 and 22 hours?

- Commulative probability P(a<X<b)=F(b)-F(a), where Fx is the accumulated probability.
*/

#include <iostream>
#include <array>
#include <cmath>

float cum_prob_normal(float x, float mu, float stdev)
{
    return 0.5 * (1 + std::erf( (x-mu) / (stdev*std::sqrt(2)) ) ) ;
}

int main()
{
    /// Hard coded (for testing).
    float mu = 20.0 ;   // Mean.
    float stdev = 2.0 ; // Standard deviation.
    float x1 = 19.5 ;
    float x2_l = 20.0 ;
    float x2_u = 22.0 ;

    /// 1) P(X<19.5)
    printf("%.3f\n",cum_prob_normal(x1,mu,stdev)) ;

    /// 2) P(20<X<22)
    printf("%.3f\n",cum_prob_normal(x2_u,mu,stdev)-cum_prob_normal(x2_l,mu,stdev)) ;

    return 0;
}
