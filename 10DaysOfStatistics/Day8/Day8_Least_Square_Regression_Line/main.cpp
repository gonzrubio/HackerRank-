/*
Task
A group of five students enrolls in Statistics immediately after taking a Math aptitude test.
Each student's Math aptitude test score, x, and Statistics course grade, y, can be expressed as the following list of (x,y) points:
1.(95,85)
2.(85,95)
3.(80,70)
4.(75,65)
5.(60,70)
If a student scored an 80 on the Math aptitude test, what grade would we expect them to achieve in Statistics?
Determine the equation of the best-fit line using the least squares method, then compute and print the value of y when x=80.
*/

#include <iostream>
#include <vector>
#include <array>
#include <algorithm>
#include <numeric>
#include <cmath>

double mean(const std::vector<double> &X)
{
    return std::accumulate(X.begin(),X.end(),0.0) / X.size() ;
}

double Cov(const std::vector<double> &X, const std::vector<double> &Y)
{
    double mu_x = mean(X) ;
    double mu_y = mean(Y) ;

    double sum = 0 ;
    std::vector<double>::size_type ii, jj ;
    for (ii = 0, jj = 0 ; ii < X.size() ; ++ii, ++jj)
    {
        sum += (X[ii] - mu_x) * (Y[jj] - mu_y) ;
    }
    return sum / X.size() ;
}

std::array<double,2> linear_regression(const std::vector<double> &X, const std::vector<double> &Y)
{
    return {Cov(X,Y)/Cov(X,X), mean(Y)-(Cov(X,Y)/Cov(X,X))*mean(X)} ;
}
void input(std::vector<double> &X, std::vector<double> &Y)
{
    std::vector<int>::size_type idx ;
    for (idx = 0 ; idx < X.size() ; ++idx )
    {
        std::cin >> X[idx] >> Y[idx] ;
    }
}
int main()
{
    //std::vector<double> X{95,85,80,70,60} ;
    // std::vector<double> Y{85,95,70,65,70} ;
    const std::vector<int>::size_type n = 5 ;
    std::vector<double> X(n) ;
    std::vector<double> Y(n) ;
    input(X,Y) ;

    std::array<double,2> reg_coeffs = linear_regression(X,Y) ;
    printf("%.3f",reg_coeffs[0]*80+reg_coeffs[1]) ;

    return 0 ;
}
