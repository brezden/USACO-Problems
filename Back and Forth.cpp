// Problem: http://www.usaco.org/index.php?page=viewproblem2&cpid=857
// Solved on February 7th 2023

#include <bits/stdc++.h>

using namespace std;

int main()
{
	// Ten buckets from each barn
	int firstBarn[10];
	int secondBarn[10];
	int newFirstBarn[10];
	int newSecondBarn[10];

	int bucketOne, bucketTwo;
	set<int> possibleBarnValues;

	// Taking input for first barn buckets
	for (int i = 0; i < 10; i++) {
		cin >> firstBarn[i];
	}

	// Taking input for second barn buckets
	for (int i = 0; i < 10; i++) {
		cin >> secondBarn[i];
	}

	copy(firstBarn, firstBarn + 10, newFirstBarn);
	copy(secondBarn, secondBarn + 10, newSecondBarn);

	// Looping through each day to simulate the possible combos
	for (int i = 0; i < 10; i++) { // Tuesday Loop
		for (int j = 0; j < 10; j++) { // Wednesday Loop

			bucketOne = newFirstBarn[i];
			bucketTwo = newSecondBarn[j];

			// Swapping the buckets we used from the first barn to the second barn
			newFirstBarn[i] = bucketTwo;
			newSecondBarn[j] = bucketOne;

			for (int k = 0; k < 10; k++) { // Thursday Loop
				for (int y = 0; y < 10; y++) { // Friday Loop

					// Calculating the possible barn one amount. If it is unique then it will be added to the set.
					possibleBarnValues.insert(1000 - bucketOne + bucketTwo - newFirstBarn[k] + newSecondBarn[y]);
				}
			}

			// Resetting the amount of buckets in each barn back to original
			copy(firstBarn, firstBarn + 10, newFirstBarn);
			copy(secondBarn, secondBarn + 10, newSecondBarn);
		}
	}

	cout << possibleBarnValues.size();
}