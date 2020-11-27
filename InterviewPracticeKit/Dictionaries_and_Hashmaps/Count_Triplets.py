"""Given and array A, find number of tripets of indices (i,j,k) s.t. A[i], A[j], A[k]
are in geometric progression for a given common ratio r and i<j<k.

1<=n<=10^5 - The size of the array.
1<=r<=10^0=9 - The common ratio.
1<=A[i]<=10^9 - The i-th element of the input array
"""

from collections import defaultdict

def countTriplets(arr, r):
    # stores number of tuples with two elements that can be formed if we find the key
    potential_two_tuples = defaultdict(int) 
    # stores number of tuples with three elements that can be formed if we find the key
    potential_three_tuples = defaultdict(int)
    count = 0
    for k in arr:
        # k completes the three tuples given we have already found k/(r^2) and k/r  
        count += potential_three_tuples[k]
        # For any element of array we can form three element tuples if we find k*r given k / r is already found. Also k forms the second element.
        potential_three_tuples[k*r] += potential_two_tuples[k]
        # For any element of array we can form two element tuples if we find k*r. Also k forms the first element.
        potential_two_tuples[k*r] += 1 
    return count   

def main():
    tests = [[[1, 2, 2, 4], 2], # 2
             [[1, 3, 9, 9, 27, 81], 3], # 6
             [[1, 5, 5, 25, 125], 5]] # 4

    for test in tests:
        print(countTriplets(test[0], test[1]))
    

if __name__ == '__main__':
    main()