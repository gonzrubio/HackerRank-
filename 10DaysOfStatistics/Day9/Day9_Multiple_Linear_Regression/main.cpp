#include <iostream>
#include <vector>
#include <cmath>
#include <limits>
#include <algorithm>

using mat2D = std::vector<std::vector<double>> ;
using vec = std::vector<double> ;

void printAnswer(const vec &x)
{
    for (auto elem : x) std::cout << elem << "\n" ;
}

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

mat2D subMatrix(const mat2D &A, const mat2D::size_type row_del, const mat2D::size_type col_del)
{
    // Return a matrix with the i-th row and j-th column deleted.
    mat2D A_sub(A[0].size()-1, vec(A.size()-1)) ;

    mat2D::size_type row_sub{0} ;
    mat2D::size_type col_sub{0} ;
    for (mat2D::size_type irow{0} ; irow < A.size() ; irow++)
        {
            if (irow == row_del) continue ;
            for (mat2D::size_type icol{0} ; icol < A.size() ; icol++)
                {
                    if (icol != col_del) A_sub[row_sub][col_sub++] = A[irow][icol] ;
                    {
                        if (col_sub == A.size()-1)
                        {
                            col_sub = 0 ;
                            row_sub++ ;
                        }
                    }
                }
        }
    return A_sub ;
}

double det(const mat2D &A)
{
    if (A[0].size() != A.size())
    {
        std::cout << "Not a square matrix." ;
        return std::numeric_limits<double>::quiet_NaN();
    }

    if (A.size() == 1) return A[0][0] ;
    if (A.size() == 2) return A[0][0]*A[1][1]-A[0][1]*A[1][0] ;
    else
    {
        double determinant{0} ;
        for (mat2D::size_type col{0} ; col < A.size() ; ++col)
        {
            determinant += pow(-1,col)*A[0][col]*det(subMatrix(A,0,col)) ; // Do I really need to pass the row?
        }
        return determinant ;
    }
}

mat2D cofactor(const mat2D &A)
{
    mat2D C(A[0].size(), vec(A.size())) ;

    for (mat2D::size_type irow{0} ; irow < A.size() ; irow++)
    {
        for (mat2D::size_type icol{0} ; icol < A.size() ; icol++)
        {
            C[irow][icol] = pow(-1,icol+irow)*det(subMatrix(A,irow,icol)) ;

        }
    }
    return C ;
}

mat2D adjugate(const mat2D &A)
{
    return transpose(cofactor(A)) ;
}

mat2D inv(const mat2D &A)
{
    double det_A = det(A) ;
    if (det_A == 0) std::cout << "A is not invertible.\n" ;

    mat2D A_inv(A[0].size(), vec(A.size())) ;
    mat2D A_adjugate = adjugate(A) ;

    for (mat2D::size_type irow{0} ; irow < A.size() ; irow++)
    {
        std::transform(A_adjugate[irow].begin(), A_adjugate[irow].end(), A_inv[irow].begin(),
                       [det_A](double elem) { return elem / det_A ; }) ;
    }
    return A_inv ;
}

vec matvecmul(const mat2D &A, const vec &x)
{
    if (A[0].size() != x.size())
        std::cout << "The number of columns of matrix A must agree with the number of rows in vector x.\n" ;

    vec y(A.size()) ;
    for (mat2D::size_type irow{0} ; irow < A.size() ; irow++)
    {
        double sum{0} ;
        for (mat2D::size_type icol{0} ; icol < A[irow].size() ; icol++)
        {
            sum += A[irow][icol]*x[icol] ;
        }
        y[irow] = sum ;
    }
    return y ;
}

void inputXY(mat2D &X_obs, vec &Y_obs)
{
    vec::size_type ivec{0} ;
    for (mat2D::size_type ix{0} ; ix < X_obs.size() ; ix++)
    {
        for (mat2D::size_type iy{0} ; iy < X_obs[ix].size() ; iy++ )
        {
            if (iy == 0) X_obs[ix][iy] = 1 ;
            else
            {
                std::cin >> X_obs[ix][iy] ;
                if (iy == X_obs[ix].size()-1) std::cin >> Y_obs[ivec++] ;
            }
        }
    }
}

void inputXq(mat2D &X_query)
{
    for (mat2D::size_type qset{0} ; qset < X_query.size() ; qset++)
    {
        for (mat2D::size_type mfeat{0} ; mfeat < X_query[qset].size() ; mfeat++ )
        {
            std::cin >> X_query[qset][mfeat] ;
        }
    }
}

double linear_model(const vec &x, const vec &w)
{
    double sum = w[0] ;
    for (vec::size_type elem{0} ; elem < x.size() ; elem++)
        sum += x[elem]*w[elem+1] ;
    return sum ;
}

int main()
{
    /// Sample hard-coded input.
    /*vec Y_obs{109.85, 155.72, 137.66, 76.17, 139.75, 162.6, 151.77} ;

    mat2D X_obs = { {0.18, 0.89},
                  {1.0,  0.26},
                  {0.92, 0.11},
                  {0.07, 0.37},
                  {0.85, 0.16},
                  {0.99, 0.41},
                  {0.87, 0.47} } ;

    mat2D X_query = { {0.49, 0.18},
                      {0.57,  0.83},
                      {0.56, 0.64},
                      {0.76, 0.18} } ;*/

    /// Read in inputs.
    vec::size_type m, n, q ;  // Number of features, measurements and query points.
    std::cin >> m ;
    std::cin >> n ;

    mat2D X_obs(n,vec(m+1)) ; // Account for bias.
    vec Y_obs(n) ;
    inputXY(X_obs,Y_obs) ;

    std::cin >> q ;
    mat2D X_query(q,vec(m)) ;
    inputXq(X_query) ;

    /// Analytical Least-squares solution.
    vec w = matvecmul(matmul(inv(matmul(transpose(X_obs),X_obs)),transpose(X_obs)),Y_obs) ;

    /// Forecast.
    vec Y_pred(X_query.size()) ;
    for (mat2D::size_type iq{0} ; iq < q ; iq++)
    {
        Y_pred[iq] = linear_model(X_query[iq], w) ;
    }

    printAnswer(Y_pred) ;

    return 0 ;
}
