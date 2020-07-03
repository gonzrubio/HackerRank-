/*
Task
Given two n-element data sets, X and Y, calculate the value of the Pearson correlation coefficient.

Covariance is a measure of how two random variables change together x, or the strength of their correlation.
The Pearson correlation coefficient is given by the ratio of the covariance of X and Y, and the product of the
standard deviations of X and Y.

*/

#include <iostream>
#include <vector>
#include <cmath>

void input(std::vector<float> &datas)
{
    for(auto &item : datas)
        std::cin >> item ;
}

float mean(const std::vector<float> &X)
{
    float sum{0} ;
    for (float element : X)
    {
        sum += element ;
    }
    return sum/X.size() ;
}

float Cov(const std::vector<float> &X, const std::vector<float> &Y)
{
    float mu_x = mean(X) ;
    float mu_y = mean(Y) ;

    float sum = 0 ;
    //std::vector<int>::size_type ii, jj ;
    std::size_t ii, jj ;
    for (ii = 0, jj = 0 ; ii < X.size() ; ii++, jj++)
    {
        sum += (X[ii] - mu_x) * (Y[jj] - mu_y) ;
    }
    return sum / X.size() ;
}

float Pearson_corr(const std::vector<float> &X, const std::vector<float> &Y)
{
    return Cov(X,Y) / (std::sqrt(Cov(X,X)*Cov(Y,Y))) ;
}

int main()
{
    // Hard coded for testing.
    // std::vector<float> X{10, 9.8, 8, 7.8, 7.7, 7, 6, 5, 4, 2} ;
    // std::vector<float> Y{200, 44, 32, 24, 22, 17, 15, 12, 8, 4} ;

    std::vector<int>::size_type n ;
    std::cin >> n ;
    std::vector<float> X(n) ;
    std::vector<float> Y(n) ;

    input(X) ;
    input(Y) ;

    printf("%.3f", Pearson_corr(X,Y)) ;

    return 0 ;
}
