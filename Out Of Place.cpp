// Problem: http://www.usaco.org/index.php?page=viewproblem2&cpid=785
// Solved on: February 11th 2023

#include <bits/stdc++.h>

using namespace std;

int main(){

    int n, temp;
    int answer = -1; // Need to start at -1 since we will double count the inital swap

    cin >> n;

    // Max amount of cows is 100
    int initialCowID[100];
    int sortedCowID[100];
    
    // Taking in the input 
    for (int i = 0; i < n; i++){
        cin >> temp;
        sortedCowID[i], initialCowID[i] = temp;
    }

    // Sorting the cows so we can compare the array with the
    // sorted array to see the amount of swaps we need
    sort(sortedCowID, sortedCowID + n);

    for (int i = 0; i < n; i++){

        // Checking if the order of the first array
        // is different then the sorted array
        if (initialCowID[i] != sortedCowID[i]){
            answer++; // If they are the same then we need a swap
        }
    }

    cout << answer;
}