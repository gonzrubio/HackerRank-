/// This solution with map implementation assumes the keys are not repeated.
/// Need to use another approach. Repeat first then sort.

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
#include <map>
#include <algorithm>

struct Quartiles
{
    int q1,q2,q3 ;
};

std::map<int,int> makeHash(const std::vector<int> &k, const std::vector<int> &v, int n)
{   /// Make hashmap with number(k)-frequency(v) pairs.
    std::map<int,int> XF ;
    for (int ii = 0 ; ii < n ;ii++)
        XF[k[(unsigned)ii]] = static_cast<int>(v[(unsigned)ii]) ;

    return XF ;
}

std::vector<int> makeS(std::vector<int> &X, std::map<int,int> &XF)
{
    std::vector<int> S ;
    std::sort(X.begin(),X.end()) ; // Sort (default, non-decreasing).

    for (auto elem : X)
    {   // Loop through sorted array.
        for (int jj = 0 ; jj < XF[elem] ; jj++)
        {   // Populate frequency-i number of times.
            S.push_back(elem) ;
        }
    }
    return S ;
}

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

int main()
{
    /// Read in vector
    int n = 6 ;
    std::vector<int> X{6, 12, 8, 10, 20, 16} ;
    std::vector<int> F{5, 4, 3, 2, 1, 5} ;
    //int n = 20 ;
    //std::vector<int> X{10, 40, 30, 50, 20, 10, 40, 30, 50, 20, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10} ;
    //std::vector<int> F{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 40, 30, 50, 20, 10, 40, 30, 50, 20} ;
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
    }
    */
    /// Make hashmap
    std::map<int,int> XF = makeHash(X, F, n) ;

    /// Make S
    std::vector<int> S = makeS(X, XF) ;

    /// Compute quartiles and print interquartile range as float.
    Quartiles qs = quartiles(S) ;
    printf("%.1f", static_cast<double>(qs.q3-qs.q1)) ;

    return 0;
}
