/*
ie. 1
In
6 (# of words in magazine) 4 (# of words in note)
give me one grand today night (magazine)
give one grand today (Note)
Out
Yes

ie. 2
In
6 - Magazine 5 - Note
two times three is not four - Magazine
two times two is four - Note
Out
No
*/

#include <iostream>
#include <vector>
#include <string>
#include <map>

void checkMagazine(std::vector<std::string> magazine, std::vector<std::string> note)
{
    // The magazine is the dictionary. Key is word (str), field is how many (int).
    std::map<std::string,int> myDict ;

    /// Fast: O(a + b)
    for (const std::string &word : magazine) // const to not modify and reference for performance.
        myDict[word]++ ; // If dict is empty no need to check if word exists.

    for (const std::string &word : note) // const to not modify and reference for performance.
    {   // Decrease count if seen.
        if (0 < myDict[word]) myDict[word]-- ;
        else
        {   // Count is at zero meaning no more available words. Not possible.
            std::cout << "No" ;
            return ;
        }
    }
    std::cout << "Yes" ; // Possible. Survived all iterations.

    /* Slow long solution
    // Make a dictionary from the magazine.
    for (std::string word : magazine)
    {   // If not found, add and initialize count to 1.
        if (myDict.find(word) == myDict.end() )
        {
            myDict.insert( std::pair<std::string,int>(word,1) ) ;
        }
        else myDict[word] += 1 ; // found, increase count.
    }

    // Make an empty dictionary of seen with count.
    std::map<std::string,int> seen ;

    // Iterate through words in note.
    for (std::string word : note)
    {   // If word not in dictionary, exit.
        if (myDict.find(word) == myDict.end())
        {
            std::cout << "No" ;
            return ;
        }
        else // It is in the dictionary. Now check in seen.
        {   // If not in seen, add and initialize count to 1.
            if (seen.find(word) == myDict.end())
            {
                seen.insert( std::pair<std::string,int>(word,1) ) ;
            }
            // Now check count. count seen < count dictionary , increase count.
            else if (seen[word] < myDict[word])
            {   // Need stricly less than because on next find (else condition below)
                // count would have to increase and would be largen than available.
                seen[word] += 1 ;
            }
            // Otherwise not enough words in magazine to replicate message
            else //
            {
                std::cout << "No" ;
                return ;
            }
        }
    }
    std::cout << "Yes" ;*/
}

int main()
{
    //std::vector<std::string> magazine{ {"give", "me", "one", "grand", "today", "night"} } ;
    //std::vector<std::string> note{ {"give", "me", "one", "grand", "today"} } ;

    std::vector<std::string> magazine{ {"two", "times", "three", "is", "not", "four"} } ;
    std::vector<std::string> note{ {"two", "times", "two", "is", "four"} } ;

    checkMagazine(magazine, note) ;

    return 0;
}
