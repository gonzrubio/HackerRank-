/*
A large elevator can transport a maximum of 9800 pounds. Suppose a load of cargo containing 49 boxes
must be transported via the elevator. The box weight of this type of cargo follows a distribution with
a mean of mu=205 pounds and a standard deviation of sigma=15 pounds.

What is the probability that all 49 boxes can be safely loaded into the freight elevator and transported?

Central limit theorem (CLT) - If X is a random variable that belongs to any distribution with mean mu and
standard deviation sigma, then for a large eneough n the sum of these random variables will converge to a normal distribution.

For large n, the distributionn of the sample sums S_n is close to the normal distribution N(mu',sigma') where:
mu' = n*mu
sigma' = sqrt(n)*sigma

Now that we have this new distribution we want the probability that the sum (lbs) is less thant the maximum weight
the elevator can take. In other words, find the cumulative probability for x = 9800.
*/

#include <iostream>
#include <cmath>

float cum_prob_normal(float x, float mu, float sigma)
{
    return 0.5 * (1 + std::erf( (x-mu) / (sigma*std::sqrt(2)) ) ) ;
}

int main()
{
    // Read input.
    float max_weight, n, mu, sigma ;
    std::cin >> max_weight ;
    std::cin >> n ;
    std::cin >> mu ;
    std::cin >> sigma ;

    //Sample distribution parameters.
    float mu_normal = n*mu ;
    float sigma_normal = std::sqrt(n)*sigma ;

    // Cumulative probabilty of getting a weight sum less than max_weight.
    printf("%.4f", cum_prob_normal(max_weight, mu_normal, sigma_normal)) ;

    return 0 ;
}
