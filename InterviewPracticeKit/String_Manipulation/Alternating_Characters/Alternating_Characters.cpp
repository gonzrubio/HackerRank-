/*
Count the number of deletions that would be neede to change
the input string such that there are no matching adjacent characters.

In
5 -> NUmber of queries
AAAA
BBBBB
ABABABAB
BABABA
AAABBB

Out
3
4
0
0
4
*/

#include <iostream>
#include <string>
#include <vector>

int alternatingCharacters(std::string s)
{   /// Return the number of deletions. No need to actually print the string.
    int deletions = 0 ;
    auto len{s.length()-1} ;
    for (int unsigned ii{0}; ii < len ;ii++ )
        {   // Compare adjacent characters.
            if (s[ii] == s[ii+1]) deletions++ ;
        }
    return deletions ;
}


int main()
{

    std::vector<std::string> q{"AAAA","BBBBB","ABABABAB", "BABABA", "AAABBB"} ;

    for (auto elem : q)
    {
        std::cout << alternatingCharacters(elem) << "\n" ;
    }

    return 0 ;
}
