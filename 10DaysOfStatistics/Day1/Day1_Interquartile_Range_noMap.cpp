/*
In
6
6 12 8 10 20 16
5 4 3 2 1 5
Out
9.0
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

struct Quartiles
{
    int q1,q2,q3 ;
};

float median(std::vector<int> &v)
{   /// Assumes input is sorted.
     auto N{v.size()} ;
    // Array of even length. Take average of midle two elements.
    if (static_cast<int>(N) %  2 == 0)
        return 0.5*(v[(N/2)-1] + v[N/2]) ;
    // Otherwise it has odd number of elements. Return middle element.
    else return v[(N-1)/2] ;
}

Quartiles quartiles(std::vector<int> &v)
{   /// Assumes v is sorted
    Quartiles qs ;
    auto N{v.size()} ;
    std::vector<int> L ;           // Lower half.
    std::vector<int> U ;           // Lower half.

    unsigned int ui ; // Compute upper index where split happens.
    if ( N % 2 == 0 ) ui = N/2 ; //
    else ui = N/2 + 1 ; // Keep the integer part.

    for (unsigned int ii{0} ; ii < std::floor(N/2) ; ii++)
    {   // Populate lower and upper halves.
        L.push_back(v[ii]) ;
        U.push_back(v[ii+(unsigned)ui]) ;
    }

    qs.q1 = median(L) ;
    qs.q2 = median(v) ;
    qs.q3 = median(U) ;

    return qs ;
}

std::vector<int> makeS(std::vector<int> &X, std::vector<int> &F, int n)
{
    std::vector<int> S ;

    for (int ii = 0 ; ii < n ; ii++)
    {   // Loop through sorted array.
        for (int jj = 0 ; jj < F[(unsigned)ii] ; jj++)
        {   // Populate frequency-i number of times.
            S.push_back(X[(unsigned)ii]) ;
        }
    }
    std::sort(S.begin(),S.end()) ; // Sort (default, non-decreasing).

    return S ;
}

int main()
{
    /// Read in vector
    int n = 20 ;
    std::vector<int> X{10, 40, 30, 50, 20, 10, 40, 30, 50, 20, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10} ;
    std::vector<int> F{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 40, 30, 50, 20, 10, 40, 30, 50, 20} ;
    /*int n ;
    std::cin >> n ;
    int input ;
    std::vector<int> X ; ;
    for (int ii=0 ; ii< n ; ii++)
    {
        std::cin >> input ;
        X.push_back(input) ;
    }
    std::vector<int> F ; ;
    for (int ii=0 ; ii< n ; ii++)
    {
        std::cin >> input ;
        F.push_back(input) ;
    }*/

    /// Make S and sort.
    std::vector<int> S = makeS(X, F, n) ;

    /// Compute quartiles and print interquartile range as float.
    Quartiles qs = quartiles(S) ;
    printf("%.1f", static_cast<double>(qs.q3-qs.q1)) ;

    return 0 ;
}
