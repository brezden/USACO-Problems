// Problem: http://www.usaco.org/index.php?page=viewproblem2&cpid=963
// Solved on January 31st 2023

#include <bits/stdc++.h>

using namespace std;

int positions[10][20];
int positionTally[20][20];

int main()
{
    int k, n;
    int count = 0;

    cin >> k >> n;

    // Input
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < n; j++) {
            cin >> positions[i][j];
            positions[i][j]--;  //Reason for minus is to make the cows in a zero index.
        }
    }

    // Checking tally
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < n; j++) {
            // Checking all the values infront of the current value and adding a count to its tally
            for (int k = j + 1; k < n; k++) { //Need to be infront of value (j + 1)
                positionTally[positions[i][j]][positions[i][k]]++;
            }
        }
    }

    // Calculating which tally is equal to k
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (positionTally[i][j] == k) { // Go across list and find which values are equal to k
                count++;
            }
        }
    }
    
    cout << count;

}

