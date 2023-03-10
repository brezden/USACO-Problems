// Problem: https://cses.fi/problemset/result/5631703/
// Solved on March 9th 2023

#include <iostream>
#include <cstring>

using namespace std;
long long grid[1002][1002];
int mod = 1e9 + 7;

int main(){
    int n;
    char x;
    memset(grid,0,sizeof(grid));

    cin >> n;
    // Taking input for 2D Array
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            cin >> x;
            if (x != '.'){
                grid[i][j] = -1;
            }
        }
    }

    if (grid[1][1] != -1){
        grid[1][1] = 1;
    } else{
        grid[1][1] = 0;
    }

    long c = 0;
    long d = 0;

    for (int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if (grid[i][j] != -1){
                if (i == 1 && j == 1){
                    continue;
                }
                c = 0;
                d = 0;

                if (grid[i-1][j] != -1){
                    c = grid[i-1][j];
                }

                if (grid[i][j-1] != -1){
                    d = grid[i][j-1];
                }

                grid[i][j] = (c + d) % mod;
            }
        }
    }

    if (grid[n][n] == -1){
        cout << 0;
    } else {
        cout << grid[n][n];
    }
}