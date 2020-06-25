/*
The number of tickets purchased by each student for the University X vs. University Y football game
follows a distribution that has a mean of mu=2.4 and a standard deviation of sigma=2.0.

A few hours before the game starts, 100 eager students line up to purchase last-minute tickets.
If there are only 250 tickets left, what is the probability that all  students will be able to purchase tickets?

Solution:
We are given the mean and standard deviation of the distribution of the number of tickets purchased per student.
We want to know what is the probability that all 100 students purchase less than 250 tickets together.
In other words, we need to know the probability that the sum of tickets is less than 250 where the distribution is normal
and computed from the central limit theorem.

The sample sum mean and sample sum standard deviation are as folows:
mu' = n*mu
sigma' = sqrt(n)*sigma
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
    float tix_available, n, mu, sigma ;
    std::cin >> tix_available ;
    std::cin >> n ;
    std::cin >> mu ;
    std::cin >> sigma ;

    //Sample distribution parameters.
    float mu_normal = n*mu ;
    float sigma_normal = std::sqrt(n)*sigma ;

    // Cumulative probabilty of getting a weight sum less than tix_available.
    printf("%.4f", cum_prob_normal(tix_available, mu_normal, sigma_normal)) ;

    return 0 ;
}
