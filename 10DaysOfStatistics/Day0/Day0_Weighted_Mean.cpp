/*
In
5
10 40 30 50 20
1 2 3 4 5
Out
32.0 (One decimal place)
*/


#include <iostream>
#include <vector>

float weightedMu(const std::vector<int> &v, const std::vector<int> &w)
{
    auto len{v.size()} ;
    float numerator{0} ;
    float denominator{0} ;
    for (unsigned int ii{0} ; ii < len ; ii++)
    {
        numerator += v[ii] * w[ii] ;
        denominator += w[ii] ;
    }
    return numerator / denominator ;
}

int main()
{
    //std::vector<int> X{10,30,40,50,20} ;
    //std::vector<int> w{1,2,3,4,5} ;

    //std::vector<int> X{10,40,30,50,20,10,40,30,50,20} ;
    //std::vector<int> w{1,2,3,4,5,6,7,8,9,10} ;

    std::vector<int> X{10,40,30,50,20,10,40,30,50,20,1,2,3,4,5,6,7,8,9,10} ;
    std::vector<int> w{1,2,3,4,5,6,7,8,9,10,10,40,30,50,20,10,40,30,50,20} ;

    /*int N{0} ;
    std::cin >> N ;
    int input ;

    std::vector<int> X ;
    for (int i = 0 ; i < N ; i++)
    {
        std::cin >>  input ;
        X.push_back(input) ;
    }

    std::vector<int> w ;
    for (int i = 0 ; i < N ; i++)
    {
        std::cin >>  input ;
        w.push_back(input) ;
    }*/

    printf("%.1f",weightedMu(X,w)) ;

    return 0;
}
