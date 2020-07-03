/*
Task
Given two n-element data sets, X and Y, calculate the value of the Spearman's rank correlation coefficient.

The Spearman's rank correlation coefficient is the Pearson correlation coefficient of their ranks.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>

double mean(const std::vector<double> &X)
{
    double sum{0} ;
    for (double element : X)
    {
        sum += element ;
    }
    return sum/X.size() ;
}

double Cov(const std::vector<double> &X, const std::vector<double> &Y)
{
    double mu_x = mean(X) ;
    double mu_y = mean(Y) ;

    double sum = 0 ;
    //std::vector<int>::size_type ii, jj ;
    std::size_t ii, jj ;
    for (ii = 0, jj = 0 ; ii < X.size() ; ii++, jj++)
    {
        sum += (X[ii] - mu_x) * (Y[jj] - mu_y) ;
    }
    return sum / X.size() ;
}

double Pearson_corr(const std::vector<double> &X, const std::vector<double> &Y)
{
    return Cov(X,Y) / (std::sqrt(Cov(X,X)*Cov(Y,Y))) ;
}

void get_Rank(const std::vector<double> &X, std::vector<double> &rank_X)
{
    std::vector<double> X_sorted = X ;             //deep copy.
    std::sort(X_sorted.begin(),X_sorted.end()) ;
    std::map<double, double> Rank_map ;

    double r = 1 ;
    for (auto element : X_sorted)
    {
        Rank_map[element] = r++ ;
    }

    for (auto element : X)
    {
        rank_X.push_back(Rank_map[element])  ;
    }
}

void input(std::vector<double> &X)
{
    for (auto &entry : X)
    {
        std::cin >> entry ;
    }
}

int main()
{
    // Hard coded for testing.
    // std::vector<double> X{10, 9.8, 8, 7.8, 7.7, 1.7, 6, 5, 1.4, 2} ;
    // std::vector<double> Y{200, 44, 32, 24, 22, 17, 15, 12, 8, 4} ;

    std::vector<double>::size_type n ;
    std::cin >> n ;
    std::vector<double> X(n) ;
    std::vector<double> Y(n) ;
    input(X) ;
    input(Y) ;

    std::vector<double> rank_X ;
    std::vector<double> rank_Y ;
    get_Rank(X,rank_X) ;
    get_Rank(Y,rank_Y) ;

    printf("%.3f", Pearson_corr(rank_X,rank_Y)) ;

    return 0 ;
}
