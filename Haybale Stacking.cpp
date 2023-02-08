// Problem: http://www.usaco.org/index.php?page=viewproblem2&cpid=104
// Solved on February 5th 2023

#include <bits/stdc++.h>
using namespace std;

int main()
{
	long long haybales[2000001];
	int n, k, currentSum, a, b = 0;
	cin >> n >> k;

	// Taking in the range input and making the index
	// increased by one for the given spot.
	for (int i = 0; i < k; i++) {
		cin >> a >> b;

		haybales[a - 1]++; 
		haybales[b]--;
	}

	// Taking the sum up to the given index and reassigning it to the index in the
	// array so then we can find the amount of haybales stacked at that given index
	for (int i = 0; i < n; i++) {
		currentSum += haybales[i];
		haybales[i] = currentSum;
	}

	// Sorting and finding the printing the median
	sort(haybales, haybales + n);
	cout << haybales[n / 2] << endl;
}