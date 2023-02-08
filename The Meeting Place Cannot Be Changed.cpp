// Problem: https://codeforces.com/contest/782/problem/B
// Solved on January 25th 2023

#include <iostream>
#include <algorithm>
using namespace std;

#define ll long long

int numberOfFriends;
ll locations[10000000];
ll velocity[10000000];

bool check(double possibleTime) {

	double rightSide = INT_MIN;
	double leftSide = INT_MAX;

	for (int i = 0; i < numberOfFriends; i++) {
		rightSide = max(rightSide, locations[i] - (velocity[i] * possibleTime));
	}

	for (int j = 0; j < numberOfFriends; j++) {
		leftSide = min(leftSide, locations[j] + (velocity[j] * possibleTime));
	}

	return (rightSide <= leftSide);

}

int main()
{
	cin >> numberOfFriends;

	for (int i = 0; i < numberOfFriends; i++) {
		cin >> locations[i];
	}

	for (int j = 0; j < numberOfFriends; j++) {
		cin >> velocity[j];
	}

	double low = 0.0;
	double high = 1e9;
	double middle;

	while ((high - low) > 1e-6) {
		middle = (high + low) / 2;

		if (check(middle)) {
			high = middle;
		}

		else {
			low = middle;
		}
	}

	printf("%.9lf ", high); //Used to print the whole value. Needs this for test cases

}
