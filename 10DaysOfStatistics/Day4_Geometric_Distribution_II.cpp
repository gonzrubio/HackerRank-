/*
The probability that a machine produces a defective product is 1/3.
What is the probability that the 1st defect is found during the first 5 inspections?

This experiment follows a negative binomial distribution.
This is simmilar to the binomial distribution with two differences.
- The number of experiments i not fixed.
- The random variable is the number of trials needed to get r successes.

In other words, we want to count the number of failures before the first success.
The negative binomial distribution has the following probability mass function:

b*(k,n,p)=((n-1)!/((k-1)!(n-k)!))*p^k*(1-p)^(n-k))
k - successful outcome.
n - number of trials.
p - Probability of sucsess of one trial.

Since we want to know during the first 5, we need the cummulative probability.
 P(X<=5) = b*(1,1,p)+...+b*(1,5,p)

*/

#include <iostream>
#include <cmath>

int fact(int n)
{
    if (n == 0) return 1 ;
    return n * fact(n-1) ;
}

int nChooseK(int n,int k)
{
    return fact(n) / (fact(k) * fact(n - k)) ;
}

float neg_binomial(int n, int k, float p)
{
    return nChooseK(n-1,k-1)*pow(p,k)*pow(1-p,n-k) ;
}

int main()
{
    const float p = 1.0/3 ; // Probability of defective product (success).
    const int k = 1 ;       // First defective product (number of successful events).
    const int n = 5 ;       // Inspection number (Number of trials).

    float cum_prob = 0 ;
    for (int ii = 1 ; ii <= n ; ii++)
    {
        cum_prob += neg_binomial(ii,k,p) ;
    }
    printf("%.3f",cum_prob) ;

    return 0;
}
