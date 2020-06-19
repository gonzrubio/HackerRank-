#include <iostream>

/*
Q: Suppose a family has  children, one of which is a boy. What is the probability that both children are boys?

The probability of an event B is the probability that the event will occur given that event A has
already occurred P(B|A).

If these are indepenedent events (they have no effect on each other) then P(A|B)=P(A) and P(B|A)=P(B).

If the events are not independent then the probability of the intersection (both events occur),
P(A and B)=P(A)P(B|A) therefore the conditional probability if B given A is P(B|A)=P(A and B)/P(A).
*/


int main()
{
    // All possible outcomes.
    // BB BG
    // GB GG

    // We want to know P(boy|boy)=P(boy and boy)/P(boy)
    // We know:
    //      - P(boy and boy)=1/4
    //      - P(boy)=3/4

    float P_boy = 3.0/4 ;
    float P_boy_and_boy = 1.0/4 ;
    float P_boy_given_boy = P_boy_and_boy / P_boy ;

    printf("The probability that both are boys given that one is a boy is: %.3f \n", P_boy_given_boy) ;

    return 0 ;
}
