// Problem: https://cses.fi/problemset/task/1633
// Solved on March 6th 2023

#include <iostream>
#include <cstring>

using namespace std;

int main(){

    int n;

    cin >> n;

    // Making array to hold combination values 
    // that has been calculated to reduce work
    long long values[n + 1]; 
    memset(values, 0, sizeof(values));

    // Initializing the initial conditions 
    values[0] = 1;

    // This is a requirment for the question
    long long mod = 1e9+7;
    
    // Calculates all the values for the array
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= 6; j++){
            // Taking the two previous about of combinations which will equal
            // current amount of combinations
            if ((i-j) >= 0){
                values[i] = (values[i] + values[i-j]) % mod;
            }
        }
    }

    cout << values[n] << endl;
}