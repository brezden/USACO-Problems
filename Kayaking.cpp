// Problem: https://codeforces.com/problemset/problem/863/B
// Solved on: February 10th 2023

#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>

using namespace std;

int main(){

    int n, temp;
    int currentWeightTotal;
    int weightTotal = 99999999;
    cin >> n;

    vector<int> weights;

    // Input for the weights
    for (int i = 0; i < (n * 2); i++){
        cin >> temp;
        weights.push_back(temp);
    }

    //Brute force for Kayak pairs
    for (int i = 0; i < ((n * 2) - 1); i++){ // Person in the first single kayak
        for (int j = i + 1; j < (n * 2); j++){ // Person in the second single kayak

            // Resetting the weights that we are looking at and the 
            // weight sum so we can recalculate another simulation
            vector<int> currentWeights;
            currentWeightTotal = 0;

            // Adding all the weights that are not in the single kayaks
            for (int k = 0; k < (n * 2); k++){
                if (k == i || k == j) {
                    // Weight is the single kayak weights
                    continue;
                } else { 
                    currentWeights.push_back(weights[k]);
                }
            }

            //Sorting the weights so we get the minimum distance and get pairs
            //to be beside each other
            sort(currentWeights.begin(), currentWeights.end());

            // Taking the difference of two kayaks and adding it to the 
            // weight total for that pair
            for (int k = 0; k < currentWeights.size(); k += 2){
                currentWeightTotal += (abs(currentWeights[k+1] - currentWeights[k]));
            }

            //Checking to see if the current total is the new minimum
            weightTotal = min(weightTotal, currentWeightTotal);
        }
    }

    cout << weightTotal;
}