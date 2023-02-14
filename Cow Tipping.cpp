// Problem: http://www.usaco.org/index.php?page=viewproblem2&cpid=689
// Solved on February 13th 2023

#include <bits/stdc++.h>

using namespace std;

string grid[10];

// Function that will flip the rectangle
void gridFlip(int x, int y){
    // Taking the {x, y} and going until we reach that coordinate
    // in the bottom right (Smallest Rectangle)
    for (int a = 0; a <= x; a++){
        for (int b = 0; b <= y; b++){
            // Flipping the 0 and 1 in the grid slots
            if (grid[a][b] == '0') grid[a][b] = '1';
            else grid[a][b] = '0';
        }
    }
}

int main(){
    int answer = 0;
    int n;

    cin >> n;

    // Taking input from the user
    for (int i = 0; i < n; i++){
        cin >> grid[i];
    }

    // Going from row right to left, bottom to top
    // [^ < - -]
    // [| < - -]
    // [| < - -]
    for (int i = n-1; i>=0; i--){
        for (int j = n-1; j>=0; j--){
            if (grid[i][j] == '1'){ // Grid cell needs a flip
                answer++; // Increasing amount of flips
                gridFlip(i, j); // Calling my grid flip function to flip the cells
            }
        }
    }

    cout << answer;
}