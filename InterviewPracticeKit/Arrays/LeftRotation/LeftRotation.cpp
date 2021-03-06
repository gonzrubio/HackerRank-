#include <iostream>
#include <vector>

std::vector<int> rotLeft(std::vector<int> a, int d)
{
    // Preallocate new vector
    int len{ static_cast<int>(a.size()) } ;
    std::vector<int> arrRot ;
    arrRot.resize((unsigned)len) ;

    for (int oldIdx = 0 ; oldIdx < len ; oldIdx++)
    {   // Calculate new index with wrap arround.
        int newIdx{ (oldIdx - d + len) % len } ;
        // Populate rotated array.
        arrRot[(unsigned)newIdx] = a[(unsigned)oldIdx] ;
    }
    return arrRot ;
}

int main()
{
    std::vector<int> arr{1,2,3,4,5} ;
    //int n{0} ;
    int n{2} ;

    std::vector<int> arrRot{rotLeft(arr,n)} ;

    std::cout << "Original array: " ;
    for (int elem : arr)
        std::cout << elem << " " ;

    std::cout << "\nAfter " << n << " rotations left: ";
    for (int elem : arrRot)
        std::cout << elem << " " ;

    return 0 ;
}
