// Problem: https://cses.fi/problemset/task/1652
// Solved on February 7th 2023

#include <bits/stdc++.h>
using namespace std;

int grid[1001][1001];

int solve(int y1, int x1, int y2, int x2) {
    return (grid[y2][x2] - grid[y1 - 1][x2] - grid[y2][x1 - 1] + grid[y1 - 1][x1 - 1]);
}

int main()
{
    
    int n, q;
    int x1, y1, x2, y2;
    string inputLine;

    cin >> n >> q;
       
    // Creating the grid given the input
    for (int i = 1; i <= n; i++) {
        cin >> inputLine;

        // Checking the character to assign to be a zero or one
        for (int j = 1; j <= n; j++) {
            if (inputLine[j - 1] == '.') {
                grid[i][j] = 0;
            }
            else {
                grid[i][j] = 1;
            }
        }

        // Making the row into a prefix sum
        for (int j = 2; j <= n; j++) {
            grid[i][j] += grid[i][j - 1];
        }
    }

    // Making the columns into a prefix sum grid
    for (int i = 1; i <= n; i++) {
        for (int j = 2; j <= n; j++) {
            grid[j][i] += grid[j - 1][i];
        }
    }

    // Taking in queries 
    for (int i = 0; i < q; i++) {
        cin >> y1 >> x1 >> y2 >> x2;
        cout << solve(y1, x1, y2, x2) << "\n";
    }
}
