/*
You are given an unordered array consisting of consecutive integers {1, 2, 3, ..., n} without
any duplicates. You are allowed to swap any two elements. Find the minimum number of swaps required
to sort the array in ascending order.

Constraints:
1 <= n <= 10^5
1 <= arr[i] <= n
*/


#include <algorithm>
#include <iostream>
#include <vector>


int minimumSwaps(std::vector<int> arr) {
	// Numbers are consecutive, non repeating and start at 1, therefore each element
	// must be in its correct index when the array is sorted.
	// This algorithm is O(n) in time and gives minimal number of swaps since every number will be
	// swapped at most once.

	int count{ 0 };
	int n{ static_cast<int>(arr.size()) };

	for (int ii{ 0 }; ii < n; ii++) {
		// check if element is in its correct position
		if (arr[ii] == ii + 1) continue;

		// Otherwise, swap it with the element occupying the right position
		std::swap(arr[ii], arr[arr[ii] - 1]);
		count++;
		ii--;
	}

	return count;
}

int main() {

	// Samples
	// std::vector<int> arr{4, 3, 2, 1};
	// std::vector<int> arr{ 2, 3, 4, 1, 5 };
	std::vector<int> arr{ 1, 3, 5, 2, 4, 6, 7 };

	std::cout << minimumSwaps(arr) << '\n';

	return 0;
}