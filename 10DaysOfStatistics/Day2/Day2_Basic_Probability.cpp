/*
Probability that the sum of two dice is at most 9
*/

#include <iostream>

int favorableSums(const int sum)
{   /// sum of two dice is at most 'sum'
    int favorable = 0 ;
    for (int i = 1 ; i < 7; i++)
    {
        for (int j = 1 ; j < 7 ; j++)
        {
            if (i+j <= sum)
            { /// Count and end inner loop early due matrix symmetry
                favorable++ ;
                continue ;
            }
        }
    }
    return favorable ;
}


int main()
{
    const int upper{9} ;
    // Number of favorable outcomes
    int favorable{favorableSums(upper)} ;
    // Calculate probability.
    std::cout << static_cast<double>(favorable)/36 ;

    return 0;
}
