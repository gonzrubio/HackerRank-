/*
The final grades for a Physics exam taken by a large group of students has a mean of 70 and a standard deviation of 10.
If we can approximate the distribution of these grades by a normal distribution, what percentage of the students:

1) Scored higher than 80 (i.e., have a grade>80)?
2) Passed the test (i.e., have a grade>=60)?
3) Failed the test (i.e., have a grade<60)?
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
    /// Hard coded for testing.
    //const int mu = 70 ;     // Mean.
    //const int sigma = 10 ;  // Standard deviation.
    //const int grade = 80 ;  // First test score.
    //const int pass = 60 ;   // Minumum passing score.

    /// Read input from STDIN.
    float mu, sigma, grade, pass ;
    std::cin >> mu ;
    std::cin >> sigma ;
    std::cin >> grade ;
    std::cin >> pass ;

    /// 1) Percentage of students with 100*P(grade>80)=100*(F(inf)-F(80)).
    printf("%.2f\n",100*(1-cum_prob_normal(grade,mu,sigma))) ;

    /// 2) Percentage of students with 100*P(grade>=60).
    printf("%.2f\n",100*(1-cum_prob_normal(pass,mu,sigma))) ;

    /// 3) Percentage of students with 100*P(grade<60).
    printf("%.2f\n",100*cum_prob_normal(pass,mu,sigma)) ;

    return 0 ;
}
