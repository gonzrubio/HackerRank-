#include <iostream>
#include <cmath>

/*
The ratio of boys to girls for babies born in Russia is 1.09. If there is child 1 born per birth,
what proportion of Russian families with exactly 6 children will have at least 3 boys?

A: The probability of succesfull outcomes,k following a binomail distribution is,
P(X=k)=(n!/(k!(n-k)!))*p^k*(1-p)^(n-k)
Here we want P(X>=k)=P(X=3)+P(X=4)+P(X=5)+P(X=6)=1-(P(X=0)+P(X=1)+P(X=2))

k - successful outcome.
n - number of trials. n! is the number of possible outcomes.
p - Probability of sucsess of one trial.
Odds = p/(1+p)
p = Odds/(1-Odds)

*/

int fact(int n)
{
    if (n == 0) return 1 ;
    return n * fact(n-1) ;
}

int nChooseK(int n,int k)
{
    return fact(n) / (fact(k) * fact(n - k)) ;
}

int main()
{
    float odds = 1.09 ;
    float p = odds/(1+odds) ;
    // printf("The Probability of having a boy is %.3f\n",p) ;

    int n = 6 ; // Number of children per family (number of trials).
    int k = 3 ; // Minimum number of boys for successful outcome.

    // Decide if it more efficient to compute the cummulative probability of
    // negative outcomes or possitive outcomes. Ignore for now since its simple to know which one is easier.
    float ans = 1 ;
    for (int ii = 0 ; ii < k ; ii++)
    {
        ans -= nChooseK(n,ii)*pow(p,ii)*pow(1-p,n-ii) ;
    }

    printf("%0.3f", ans) ;

    return 0;
}
