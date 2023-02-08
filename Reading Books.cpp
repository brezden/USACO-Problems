// Problem: https://cses.fi/problemset/task/1631/
// Solved on January 17th 2023

#include <iostream>
using namespace std;
int main()
{

	long bookAmount, currentBook;
	long sumBookAmount = 0;
	long maxBookTime = 0;

	cin >> bookAmount;

	for (int i = 0; i < bookAmount; i++) {
		cin >> currentBook;
		sumBookAmount += currentBook;

		if (currentBook > maxBookTime) {
			maxBookTime = currentBook;
		}
	}

	if ((sumBookAmount - maxBookTime) > maxBookTime) {
		cout << (sumBookAmount);
	}

	else {
		cout << (2 * maxBookTime);
	}
}
