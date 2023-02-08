// Problem: http://www.usaco.org/index.php?page=viewproblem2&cpid=595
// Solved on February 5th 2023

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    int currentRemainder, answer = 0;
    int currentSum, tempSum = 0;
    cin >> n;
    
    vector<int> cowRemainder(n + 1);
    vector<int> pairList(7);

    //Takes the input and converts the array into prefix sum then into the remainder of 7
    for (int i = 0; i < n; i++) {
        cin >> tempSum;
        cowRemainder[i + 1] = (cowRemainder[i] + tempSum) % 7;
    }

    //Initializing all the values in the array to -1
    //so we can check if it is empty or not
    for (int i = 0; i < 7; i++) {
        pairList[i] = -1;
    }

    //Loop through the remainder list and find the longest distance
    //from the previous exact remainder
    for (int i = 0; i < cowRemainder.size(); i++) {
        currentRemainder = cowRemainder[i];

        //If this remainder does not exist so far we had the value in the index
        //we are at so we can find the total distance at the end
        if (pairList[currentRemainder] == -1) {
            pairList[currentRemainder] = i;
        }

        else {
            answer = max(answer, (i - pairList[currentRemainder]));
        }
    }

    cout << answer << endl;
}