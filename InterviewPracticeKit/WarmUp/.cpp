#include <iostream>
#include <vector>
#include <map>

/*
John works at a clothing store. He has a large pile of socks that he must pair by color for sale.
Given an array of integers representing the color of each sock, determine how many pairs of socks
with matching colors there are. For example, there are n=7 socks with colors ar = [1 2 1 2 1 3 2]. There is one pair of
color  and one of color . There are three odd socks left, one of each color. The number of pairs is 2.
*/

int sockMerchant(int n, std::vector<int> ar)
{
    // n: Number of socks in the pile.
    // ar: The colors of each sock.
    // Output: integer representing the number of matching pairs of socks that are available.

    std::map<int,int> m ; // Key is digit/color and value is count/frequency.
    int total{0} ;         // Total number of pairs

    for (std::vector<int>::size_type ii{0}; ii < (unsigned)n; ii++)     // Traverse array of socks.
    {
        if (m.find(ar[ii]) == m.end()) // Does not exist.
            m[ar[ii]] = 1 ;            // Insert in map.
        else
            m[ar[ii]] += 1 ;           // Incremenet frequency.
    }

    for ( const auto &myPair : m )  // Traverse map
    {
        total += myPair.second / 2 ; // Increase total by total/2.
    }

    return total ;
}

int main()
{
    int n{9} ;
    std::vector<int> arr{10, 20, 20, 10, 10, 30, 50, 10, 20} ;
    int ans{3} ;


    if (ans == sockMerchant(n, arr))
        std::cout << "Solved\n" ;

    return 0;
}
