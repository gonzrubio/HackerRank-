/*
Return the firsr, second and third quartile.
In
9
3 7 8 5 12 14 21 13 18
Out
6
12
16
*/

#include <iostream>
#include <vector>
#include <algorithm> // sort
#include <cmath>     // floor

struct Quartiles
{
    int q1,q2,q3 ;
};

float median(std::vector<int> v)
{   /// Assumes input is sorted.
     auto N{v.size()} ;
    // Array of even length. Take average of midle two elements.
    if (static_cast<int>(N) %  2 == 0)
        return 0.5*(v[(N/2)-1] + v[N/2]) ;
    // Otherwise it has odd number of elements. Return middle element.
    else return v[(N-1)/2] ;
}

Quartiles quartiles(std::vector<int> v)
{
    Quartiles qs ;
    auto N{v.size()} ;
    std::sort(v.begin(),v.end()) ; // Using default < (non-decreasing order).
    std::vector<int> L ;           // Lower half.
    std::vector<int> U ;           // Lower half.

    unsigned int ui ; // Compute upper index where split happens.
    if ( static_cast<int>(N) % 2 == 0 ) ui = N/2 ; //
    else ui = N/2 + 1 ; // Keep the integer part.

    for (unsigned int ii{0} ; ii < std::floor(N/2) ; ii++)
    {   // Populate lower and upper halves.
        L.push_back(v[ii]) ;
        U.push_back(v[ii+ui]) ;
    }

    qs.q1 = median(L) ;
    qs.q2 = median(v) ;
    qs.q3 = median(U) ;

    return qs ;
}

int main()
{
    /// Make read input.
    //std::vector<int> X{3, 7, 8, 5, 12, 14, 21, 13, 18} ;
    int n ;
    int input ;
    std::cin >> n ;
    std::vector<int> X ;
    for (int ii=0 ; ii< n ; ii++)
    {
        std::cin >> input ;
        X.push_back(input) ;
    }

    Quartiles qs = quartiles(X) ;
    std::cout << qs.q1 << "\n" << qs.q2 << "\n" << qs.q3 ;

    return 0 ;
}
