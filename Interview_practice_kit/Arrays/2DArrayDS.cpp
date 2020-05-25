/*
    Calculate the hourglass sum for every hourglass in the 2D array.
    Print the maximum hourglass sum.

    ie. arr =
    -9 -9 -9  1 1 1
     0 -9  0  4 3 2
    -9 -9 -9  1 2 3
     0  0  8  6 6 0
     0  0  0 -2 0 0
     0  0  1  2 4 0

     The 16 hourglass sums are:
     -63, -34, -9, 12,
    -10, 0, 28, 23,
    -27, -11, -2, 10,
    9, 17, 25, 18

    The highest hourglass sum is 28 from:
    0 4 3
      1
    8 6 6

    Constraints
    -9 <= arr[i][j] <= 9
    o <= i,j <= 5
*/

#include <iostream>

void initMatrix(int nrow, int ncol, int** A)
{   // Do not pass the pointer to a pointer to int as a reference unless
    // we want to change the pointer itself. The pointer to pointer to int
    // gives access to the actual location in memory. If we wondt want to
    // change the contents then make a const.
    for (int row = 0 ; row < nrow ; row++)
    {
        for (int col = 0 ; col < ncol ; col ++)
        {
            std::cin >> A[row][col] ;
        }
    }

}

int hourglassSum(int arr_rows, int arr_columns, int **arr)
{
    // Out: an integer, the maximum hourglass sum in the array
    // In: An array of integers

    int maxSum{-63} ; // minimum possible value = -9*5

    // The hour glass matrix can only fit 4 times along each dimension in the matrix.
    for (int ii = 0 ; ii < arr_rows-2 ; ii++)
    {
        for (int jj = 0 ; jj < arr_columns-2 ; jj++)
        {   // Hourglass sum.
            int temp = arr[ii][jj]+arr[ii][jj+1]+arr[ii][jj+2]+arr[ii+1][jj+1]+arr[ii+2][jj]+arr[ii+2][jj+1]+arr[ii+2][jj+2] ;
            if (maxSum < temp ) maxSum = temp ;
        }
    }
    return maxSum ;
}

int main()
{
    const int ans{28} ;
    const int nrow{6} ;
    const int ncol{6} ;

    int **A = new int*[ncol] ;
    for (int row = 0 ; row < nrow ; row++)
    {
        A[row] = new int[ncol] ;
    }

    // Initialize matrix
    initMatrix(nrow, ncol, A) ;

    int maxSum{ hourglassSum(nrow, ncol, A) } ;

    if (maxSum == ans)
        std::cout << "Solved\n" ;

    std::cout << maxSum ;

    return 0;
}
