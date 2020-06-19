#include <iostream>

/*
Q: A bag contains  red marbles and  blue marbles. Then,  marbles are drawn from the bag, at random, without replacement.
If the first marble drawn is red, what is the probability that the second marble is blue?

A:
B = Blue
R = Red

P(B|R) = P(R and B) / P(R)
P(B|R) = (P(R|B) * P(B)) / P(R)
P(B|R) = ((1/2) * (4/7)) / (3/7)
P(B|R) = 2/3
*/

int main()
{
    float P_B = 4.0/7 ;
    float P_R = 3.0/7 ;
    float P_R_given_B = 1.0/2 ;

    float P_B_given_R = (P_R_given_B * P_B) / P_R ;
    printf("The probability that the second marble is blue given that the first is red is: ~%%%.0f.\n",P_B_given_R*100) ;

    return 0;
}
