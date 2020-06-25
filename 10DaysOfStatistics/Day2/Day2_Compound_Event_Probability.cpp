/*
Probability of 2 red one black

Solutions are mutually exclusive.
P(r,r,b U r,b,r U b,r,r)  = P(r and r and b) + P(r and b and r) + P(r and r and r)

Their events are independent:
P(r and r and b) = P(r)P(r)P(b) and so on.

*/


#include <iostream>

using namespace std;

int main()
{
    float rrb = (4/7)*(5/9)*(1/12) ;
    float rbr = (4/7)*(4/9)*(1/2) ;
    float brr = (3/7)*(5/9)*(1/2);

    std::cout << rrb*rbr*brr ;
    return 0;
}
