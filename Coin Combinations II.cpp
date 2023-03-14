// Problem: https://cses.fi/problemset/task/1636
// Solved on March 9th 2023

#include <iostream>
#include <cstring>

using namespace std;
int mod = 1e9 + 7;
int coin[101];
int combo[1000001];

int main(){
    int n, x;
    cin >> n >> x;
    memset(combo, 0, sizeof(combo));

    // Taking in coin values
    for (int i = 0; i < n; i++){
        cin >> coin[i];
    }

    combo[0] = 1;

    // For every coin checking all valid
    for (int i = 0; i < n; i++){
        int currentCoin = coin[i];
        // Checking all combinations from [1, Goal]    
        for (int j = 1; j <= x; j++){
            // Checking that value minus current coin is not negative value (Ex. 1-2 = -1)
            if (!((j - currentCoin) <= -1)){
                // Adding the existing number of combos to the amount that is found by
                // subtracting the coin by the current value
                combo[j] = (combo[j] + (combo[j - currentCoin])) % mod;
            }
        }
    }

    cout << combo[x];
}