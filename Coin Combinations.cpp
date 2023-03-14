// Problem: https://cses.fi/problemset/task/1635
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

    // Going through all values from [1]
    for (int i = 1; i <= x; i++){ 
        for (int j = 0; j < n; j++){
            int currentCoin = coin[j];
            // Making sure the value is above the zero so it is a valid arrangement
            if (!((i - currentCoin) < 0)){
                // Adding the existing number of combos to the amount that is found by
                // subtracting the coin by the current value
                combo[i] = (combo[i] + (combo[i - currentCoin])) % mod;
            }
        }
    }

    cout << combo[x];
}