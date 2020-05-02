/*
    Print median, mean and mode for the given array.
    Meadian and mean to one decimal place.
    Mode, chose the numerically smallest.

    ie.
    In:
    10
    64630 11735 14216 99233 14470 4978 73429 38120 51135 67060

    Out:
    43900.6
    44627.5
    4978
*/

#include <iostream>
#include <vector>
#include <algorithm> // sort
#include <map>


float mean(const std::vector<int> &v)
{
    float sum{0} ;
    for (const int elem : v)
        sum += elem ;

    return sum /(static_cast<int>(v.size())) ;
}

float median(std::vector<int> v)
{
    std::sort(v.begin(),v.end()) ; // Using default <.
    auto N{v.size()} ;

    // Array of even length. Take average of midle two elements.
    if (static_cast<int>(N) %  2 == 0)
        return 0.5*(v[(N/2)-1] + v[N/2]) ;
    // Otherwise it has odd number of elements. Return middle element.
    else return v[(N-1)/2] ;
}

int mode(const std::vector<int> &v)
{
    std::map<int,int> freq ;
    for (const int elem : v)
        freq[elem]++ ; //Count number of apearences.

    int mode{v[0]} ;          // Mode. Key in disctionary.
    int modef{freq[v[0]]} ;   // Frequency. value in dictionary.
    for(std::map<int,int>::iterator iter = freq.begin(); iter != freq.end(); ++iter)
    {   // Compare frequency (value). Keep key with higher frequency.
        if (modef < iter->second)
        {
            mode = iter->first ;
            modef = iter->second ;
        }  // if frequency (value) is equal then pick smaller key.
        else if (modef == iter->second)
        {
            mode = std::min(iter->first,mode) ;
            modef = freq[mode] ;
        }
    }

    return mode ;
}

int main()
{
    //std::vector<int> X{64630,11735,14216,99233,14470,4978,73429,38120,51135,67060} ;
    //auto N{X.size()} ;
    /// Read input from user.
    int N ;
    int input ;
    std::cin >> N ;
    std::vector<int> X ;

    for (int i = 0 ; i < N ; i++)
    {
      std::cin >> input ;
      X.push_back(input) ;
    }

    std::cout << "N = " << static_cast<int>(N) << "\nX = [ " ;
    for (int elem : X)
    {
        std::cout << elem << " " ;
    }
    std::cout << "]\n" ;

    /// Compute mean, median and mode.
    float mu{mean(X)} ;
    float med{median(X)} ;
    int mod{mode(X)} ;

    /// Output
    std::cout << mu << "\n" ;
    std::cout << med << "\n" ;
    std::cout << mod << "\n" ;

    return 0;
}
