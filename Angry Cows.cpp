// Problem: http://www.usaco.org/index.php?page=viewproblem2&cpid=594
// Solved on January 25th

#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll haybaleAmount, cows;
int haybales[1000000];

bool check(ll possibleRadius) {

    ll cowsUsed = 1;
    ll lowestRangeHaybale = haybales[0];

    for (int i = 0; i < haybaleAmount; i++) {
        if (haybales[i] > ((possibleRadius) + lowestRangeHaybale)) {
            cowsUsed++;
            lowestRangeHaybale = haybales[i];
        }
    }

    return (cowsUsed <= cows);
}


int main()
{
    cin >> haybaleAmount >> cows;

    for (int i = 0; i < haybaleAmount; i++) {
        cin >> haybales[i];
    }

    sort(haybales, haybales + haybaleAmount);

    ll minimumRadius = 0;
    ll x = haybaleAmount;
    ll middle;
    ll maximumRadius = haybales[haybaleAmount - 1];

    while (minimumRadius < maximumRadius) {
        middle = minimumRadius + ((x - minimumRadius) / 2);

        if (check(middle * 2)) { // Pass middle * 2 since we looking for range * 2
            maximumRadius = min(maximumRadius, middle);
            x = middle - 1;
        }

        else {
            minimumRadius = middle + 1;
        }
    }

    cout << maximumRadius << endl;
}