/*
    Given two strings, determine if they share a common substring. A substring may be as small as one character.
    All lower case.
*/

#include <iostream>
#include <string>
#include <map>
#include <algorithm> // for min

std::string smallerString(const std::string &s1, const std::string &s2, bool t)
{
    if (t)  // True. return smaller.
    {
        if (s1.length() < s2.length()) return s1 ;
        else return s2 ;
    }
    else // False return longer.
    {
        if (s2.length() <= s1.length()) return s1 ;
        else return s2 ;
    }
}

std::string twoStrings(std::string s1, std::string s2)
{
    std::map<char,int> myDict ; // Make a dictionary of unique characters in smaller word.
    for (char c : smallerString(s1,s2,true))
    {   // If not in dictionary, add. Otherise skip.
        if (myDict.find(c) == myDict.end())
        {
            myDict[c]++ ;
        }
        else continue ;
    }

    for (char c : smallerString(s1,s2,false))
    {   // Iterate trough array. Need at least one match.
        if ( myDict.find(c) != myDict.end() ) return "YES" ;
    }

    return "NO" ; // No matches.
}


int main()
{
    //std::cout << smallerString("hello","world",false) ;
    std:: cout << twoStrings("hello","world") << "\n" ;
    std:: cout << twoStrings("hi","world") << "\n" ;

    return 0;
}
