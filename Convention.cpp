// Problem: http://www.usaco.org/index.php?page=viewproblem2&cpid=858
// Solved on January 24th 2023

#include <bits/stdc++.h>
#define ll long long

using namespace std;


ll amountOfCows, amountOfBusses, busLimit;
vector<ll> arrivalTimes;

bool check(ll possibleTime) {
    ll busCount, currentCow, minCowWaitingTime;

    busCount = 0;
    currentCow = 0;
    minCowWaitingTime = 0;

    while (currentCow < amountOfCows) {
        if (currentCow == minCowWaitingTime) {
            busCount++;
        }

        //If the cow cannot fit in the possible time
        if ((arrivalTimes[currentCow] - arrivalTimes[minCowWaitingTime]) > possibleTime) {
            minCowWaitingTime = currentCow;
        }

        //Checking the amount of cows on the bus. If it exceeds
        //then we need to assign the next cow to the min waiting
        else if ((currentCow - minCowWaitingTime + 1) == busLimit) {
            minCowWaitingTime = ++currentCow;
        }

        //Moving onto next cow
        else { 
            currentCow++;
        }
    }

    return (busCount <= amountOfBusses);
}


int main()
{
    ll minWaitingTime, maxWaitingTime, middle;

    cin >> amountOfCows >> amountOfBusses >> busLimit;
    arrivalTimes.resize(amountOfCows);

    for (int i = 0; i < amountOfCows; i++){
        cin >> arrivalTimes[i];
    }

    sort(arrivalTimes.begin(), arrivalTimes.end());

    minWaitingTime = 0;
    maxWaitingTime = arrivalTimes[amountOfCows - 1] - arrivalTimes[0];
 
    while (maxWaitingTime > minWaitingTime) {
        middle = minWaitingTime + (maxWaitingTime - minWaitingTime) / 2;

        if (check(middle)) {
            maxWaitingTime = middle;
        }

        else {
            minWaitingTime = middle + 1;
        }
    }

    cout << minWaitingTime << endl;
}