/*
Task
The regression line of y on x is 3x+4y+8=0, and the regression line of x on y is 4x+3y+7=0.
What is the value of the Pearson correlation coefficient?

We want to find the Pearson correlation coefficient of the data set that gave the regression parameters above.
y = -3/4x-2
x = -3/4y-7/4
P(x,y)=beta_xy*sigma_x/sigma_y
P(y,x)=beta_yx*sigma_y/sigma_x
We know P(y,x)=P(x,y) since Cov(x,y)=Cov(y,x)
P^2 = beta_xy*beta_yx so P = +- sqrt(beta_xy*beta_yx)
*/

#include <iostream>


int main()
{

    printf("%.3f",-3.0/4) ;

    return 0 ;
}
