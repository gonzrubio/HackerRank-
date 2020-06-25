/*
A manufacturer of metal pistons finds that, on average, 12% of the pistons they manufacture
are rejected because they are incorrectly sized. What is the probability that a batch of  pistons will contain:

1) No more than 2 rejects?
A: The probability of succesfull outcomes,k following a binomail distribution is,
P(X=k)=(n!/(k!(n-k)!))*p^k*(1-p)^(n-k)
Here we want P(X<=2)=P(X=0)+P(X=1)+P(X=2)


2) At least 2 rejects?
A: The probability of succesfull outcomes,k following a binomail distribution is,
P(X=k)=(n!/(k!(n-k)!))*p^k*(1-p)^(n-k)
Here we want P(X>=2)=P(X=2)+...+P(X=10)=1-P(X<=2)+P(X=2)

k - successful outcome.
n - number of trials. n! is the number of possible outcomes.
p - Probability of sucsess of one trial.
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

float binomial(int n, int k, float p)
{
    return nChooseK(n,k)*pow(p,k)*pow(1-p,n-k) ;
}

int main()
{
    const int n = 10 ;     // Number of experiments (batch size).
    const float p = 0.12 ; // Probability of rejection.
    const int k = 2 ;      // Successfull.

    /// 1) No more than 2 rejects.
    float p_most2 = 0 ;
    for (int ii = 0 ; ii <=k ; ii++)
    {
        p_most2 += binomial(n,ii,p) ;
    }
    printf("%.3f\n",p_most2) ;

    /// 1) Less than 2 rejects.
    float p_least2 = 1 - p_most2 + binomial(n,k,p) ;
    printf("%.3f",p_least2) ;

    return 0 ;
}
