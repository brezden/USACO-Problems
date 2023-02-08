// Problem: http://www.usaco.org/index.php?page=viewproblem2&cpid=896
// Solved on January 25th 2023

#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll mountainAmount;
ll x[100000]; //Stores center of mountain (x value)
ll y[100000]; //Stores height of mountain (y value)
ll positive[100000]; //Stores upper bound
ll negative[100000]; //Stores lower bound
ll counter[100000]; // Stores a counter that will be used to sort the list
                    // but still have track of which value we are looking at

// This function is used for the sorting of the mountain heights. (Third parameter in sort)
bool compareHeights(int x, int y) { 
    if (negative[x] == negative[y]) return (positive[x] > positive[y]);
    return (negative[x] < negative[y]);
}

int main()
{
    cin >> mountainAmount;

    for (int i = 0; i < mountainAmount; i++) {
        cin >> x[i] >> y[i];
        positive[i] = x[i] + y[i]; // Getting the positive range
        negative[i] = x[i] - y[i]; // Getting the negative range
        counter[i] = i; // Storing the value of the loop into an array for sort
    }

    // Third parameter in this function will to sort the height of the mountains.
    sort(counter, counter + mountainAmount, compareHeights);

    int maxPositionInterval = 0;
    int mountainCounter = 0;

    for (int j = 0; j < mountainAmount; j++) {
        ll current = positive[counter[j]];

        if (current > maxPositionInterval) { //If mountain is outside of range
            mountainCounter++; // Increase the moutain that the cow can see
            maxPositionInterval = current; // Set the new interval start to the current mountain
        }
    }

    cout << mountainCounter << endl;

}
