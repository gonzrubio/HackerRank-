/*
Probability two dice in single toss have differen value and their sum is zero.
 1) Do joint probability
 2) Simple proability definition : P = favorable/total

*/
#include <iostream>

int favorableSum(const int sum)
{   /// sum of two dice is 'diference'
    int favorable = 0 ;
    for (int i = 1 ; i < 7; i++)
    {
        for (int j = 1 ; j < 7 ; j++)
        {
            if (i+j == sum && i != j)
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
    /// Favorable outcomes: Sum is 6 and dice values are not equal
    const int favorable{favorableSum(6)} ;
    std::cout << "There are " << favorable << " favorable outcomes.\n" ;

    /// probability
    std::cout << "Probability = " << static_cast<double>(favorable)/36 << "\n" ;

    return 0;
}
