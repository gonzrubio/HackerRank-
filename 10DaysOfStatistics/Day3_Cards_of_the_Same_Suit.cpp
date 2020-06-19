#include <iostream>

/*
Q: You draw  cards from a standard -card deck without replacing them. What is the probability that both cards are of the same suit?

A1: Using conditional probability - What is the probability the second card is of the same as the first given the first can be anything?
We want to solve P(suitA and suitA)=P(any_card)P(suitA|any_card)

A2: Using combinations and permutations -
*/

int nChoosek(int n, int k)
{
    if (k > n) return 0;
    if (k * 2 > n) k = n-k;
    if (k == 0) return 1;

    int result = n;
    for( int i = 2; i <= k; ++i ) {
        result *= (n-i+1);
        result /= i;
    }
    return result;
}


int main()
{
    // Conditional probability.
    float P_any = 1.0 ;         // Any card we draw has probability of 1.
    float P_suitA_any = 12.0/51 ; // There are now 52 cards left and 12 are of the same suit.

    float P_suitA_suitA_1 = P_any * P_suitA_any ;
    printf("The probability that both cards are of the same suit is ~ %%%.0f.\n", P_suitA_suitA_1*100) ;

    // Combinations and permutations.
    // Count ways to select a suit and two cards from that suit. Divide by all ways to select two cards of any suit.
    float P_suitA_suitA_2 = static_cast<float>(nChoosek(4, 1))*nChoosek(13, 2)/nChoosek(52, 2) ;
    printf("The probability that both cards are of the same suit is ~ %%%.0f.\n", P_suitA_suitA_2*100) ;

    return 0 ;
}
