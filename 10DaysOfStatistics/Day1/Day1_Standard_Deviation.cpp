#include <iostream>
#include <vector>
#include <cmath> // pow, sqrt

double mean(const std::vector<int> &v)
{
    double sum{0} ;
    for (const int elem : v)
        sum += elem ;
    return sum / v.size() ;
}

double variance(const std::vector<int> &X)
{
    double mu{mean(X)} ; // Expected value, mu(X).
    //std::cout << "mu(X) = " << mu << "\n" ;

    double var{0} ;      // Variance (sigma squared).
    for (int elem : X)
        var += std::pow((elem - mu),2) ;
    //std::cout << "variance = " << var << "\n" ;
    return var/X.size() ;
}

int main()
{
    /// Input array
    //std::vector<int> X{10,40,30,50,20} ;
    int n ;
    std::cin >> n ;
    int input ;
    std::vector<int> X ;
    for (int i = 0 ; i < n ; i++)
    {
        std::cin >> input ;
        X.push_back(input) ;
    }

    /// Calculate and print standard deviation (sigma) to one decimal point.
    printf("%.1f",std::sqrt(variance(X))) ;

    return 0 ;
}
