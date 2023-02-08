// Problem: http://www.usaco.org/index.php?page=viewproblem2&cpid=736
// Solved on January 31st 2023

#include <bits/stdc++.h>

using namespace std;

int main()
{   
	int n, m;
	int answer = 0;
	bool flagger = true;

    cin >> n >> m;

	vector<vector<char>> spotCows(n, vector<char>(m));
	
	for (int i = 0; i < n; i++) { // Rows
		for (int j = 0; j < m; j++) { // Columns
			cin >> spotCows[i][j]; // Assigning row and column for cow character
		}
	}

	vector<vector<char>> plainCows(n, vector<char>(m));

	for (int i = 0; i < n; i++) { // Rows
		for (int j = 0; j < m; j++) { // Columns
			cin >> plainCows[i][j]; // Assigning row and column for cow character
		}
	}

	// Now that we have the two different sections of cows we can begin
	// to search each column and check if the values work out

	set<char> checkCows; // Storing all the checked values into a set

	for (int i = 0; i < m; i++) { // Each Column

		// Adding all the plain cows into the checked set
		for (int j = 0; j < n; j++) {
			checkCows.insert(plainCows[j][i]);
		}

		// Checking to see if any of the spotted cows has the same
		// char as the plain cows. If so we know that this is not 
		// a valid column and can turn the flagger on

		for (int j = 0; j < n; j++) {
			if (checkCows.count(spotCows[j][i]) > 0) {
				flagger = false;
				break;
			}
		}

		// If the flagger is still true then we know that the column
		// is a valid column so we can increase the answer by one

		if (flagger) {
			answer++;
		}

		// Reseting flag for next column
		flagger = true;
		checkCows.clear();
	}

	cout << answer << endl;
}
