// Problem: http://www.usaco.org/index.php?page=viewproblem2&cpid=835
// Solved on February 10th 2023

#include <bits/stdc++.h>

using namespace std;

int main(){

    int n, temp;
    int counter;

    cin >> n;

    vector<int> cows;

    // Taking in the input from the user for the cow number
    for (int i = 0; i < n; i++){
        cin >> temp;
        cows.push_back(temp);
    }

    // Sorting the cows from descending order
    sort(cows.begin(), cows.end(), greater<int>());

    for (int i = 0; i < n; i++){

        // Checking if the amount of cows in the line and the cow number
        if (cows[i] >= i){
            counter++;
        }
    }

    cout << counter;
}