/*
Fit a linear model that depends on m features plus a constant, based on n different feature sets.

*/


#include <iostream>
#include <vector>
#include <cmath>

using mat2D = std::vector<std::vector<double>> ;
using vec = std::vector<double> ;

void printMatrix(const mat2D &A)
{
    for (auto row : A)
    {
        for (auto val : row)
        {
            std::cout << val << " " ;
        }
        std::cout << "\n" ;
    }
}

mat2D transpose(const mat2D &A)
{
    mat2D A_T(A[0].size(), vec(A.size()));
    for (mat2D::size_type ii{0} ; ii < A[0].size() ; ++ii)
    {
        for (mat2D::size_type jj{0} ; jj < A.size() ; ++jj)
        {
            A_T[ii][jj] = A[jj][ii] ;
        }
    }
    return A_T ;
}

mat2D matmul(const mat2D &A, const mat2D &B)
{
    const mat2D::size_type nrow_A = A.size() ;
    const mat2D::size_type ncol_A = A[0].size() ;
    const mat2D::size_type nrow_B = B.size() ;
    const mat2D::size_type ncol_B = B[0].size() ;
    if (ncol_A != nrow_B) std::cout << "Columns of A != rows of B." ;

    mat2D AB (nrow_A, vec(ncol_B)) ; // Preallocate square matrix.
    for (mat2D::size_type irow = 0 ; irow < nrow_A ; ++irow)
    {
        for (mat2D::size_type icol = 0 ; icol < ncol_B ; ++icol)
        {
            for (mat2D::size_type k = 0 ; k < ncol_A ; ++k)
            {
                AB[irow][icol] += A[irow][k] * B[k][icol] ;
            }
        }
    }
    return AB ;
}

double det(mat2D A)
{   /*Convert square matrix to upper triangular then multiply diagonal elements to get determinant.*/
    /* Modified rom https://www.geeksforgeeks.org/determinant-of-a-matrix/ */

    const mat2D::size_type n = A[0].size() ;
    int num1,num2,det = 1,total = 1; // Initialize result
    mat2D::size_type index ;

    // temporary array for storing row
    int temp[n + 1];

    //loop for traversing the diagonal elements
    for(mat2D::size_type i = 0; i < n; i++)
    {
        index = i; // initialize the index

        //finding the index which has non zero value
        while(A[index][i] == 0 && index < n) {
            index++;

        }
        if(index == n) // if there is non zero element
        {
            // the determinat of matrix as zero
            continue ;

        }
        if(index != i)
        {
            //loop for swaping the diagonal element row and index row
            for(mat2D::size_type j = 0; j < n; j++)
            {
                std::swap(A[index][j],A[i][j]);
            }
                //determinant sign changes when we shift rows
                //go through determinant properties
                det = det*std::pow(-1,index-i);
       }

       //storing the values of diagonal row elements
       for(mat2D::size_type j = 0; j < n; j++)
       {
           temp[j] = A[i][j];

       }
       //traversing every row below the diagonal element
       for(mat2D::size_type j = i+1; j < n; j++)
       {
           num1 = temp[i]; //value of diagonal element
           num2 = A[j][i]; //value of next row element

           //traversing every column of row
           // and multiplying to every row
           for(mat2D::size_type k = 0; k < n; k++)
           {
               //multiplying to make the diagonal
               // element and next row element equal
               A[j][k] = (num1 * A[j][k]) - (num2 * temp[k]);

           }
           total = total * num1; // Det(kA)=kDet(A);
           }

    }

    //mulitplying the diagonal elements to get determinant
    for(mat2D::size_type i = 0; i < n; i++)
    {
        det *= A[i][i];

    }
    return (det/total); //Det(kA)/k=Det(A);
}

mat2D comatrix(mat2D A)
{
    return A ;
}

mat2D adjugate(mat2D A)
{
    // Make own fucntion that computes the transpose of the cofactor matrix.
    // Helper function to compute the cofactor amtrix.
    return comatrix(transpose(A)) ;
}


int main()
{
    // Sample hard-coded input. (abstract functions to get inputs).
    //int m{2} ; // # of Features.
    //int n{7} ; // # of Observations.
    mat2D X_obs = { {0.18, 0.89},
                  {1.0,  0.26},
                  {0.92, 0.11},
                  {0.07, 0.37},
                  {0.85, 0.16},
                  {0.99, 0.41},
                  {0.87, 0.47} } ;
    //vec Y_obs{109.85, 155.72, 137.66, 76.17, 139.75, 162.6, 151.77} ;
    mat2D tmp = matmul(transpose(X_obs),X_obs) ;
    printMatrix(adjugate(tmp)) ;
    //std::cout << "\n" << transpose(tmp)/det(tmp) ;

    // Get query/print query
    /*4
    0.49 0.18
    0.57 0.83
    0.56 0.64
    0.76 0.18*/
    return 0 ;
}
