// Problem: https://cses.fi/problemset/task/1085
// Solved on January 24th 2023

#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

long long n, k;
vector<long long> values(200000);

bool check(long long mid) {

    long long subArray = 0;
    long long counter = 0;
    long long sum = 0;

    for (; subArray < k; subArray++) { // Going through the amount of sub arrays
        for (; (counter < n) && ((sum + values[counter]) <= mid); counter++) { // Sorting through the sub arrays
            sum = sum + values[counter];
        }
        sum = 0;
    }
    return (counter >= n);
}


int main()
{
    long long maxValue = 0;
    cin >> n >> k;

    //Taking input for the vector
    for (int i = 0; i < n; i++) {
        cin >> values[i];
        maxValue = max(maxValue, values[i]);
    }

    long long low = 0; //Lowest value can be the highest value in the array
    long long high = maxValue * n; //Highest can be all the values in the array as max
    long long middle;

    while (low < high) {
        middle = round((high + low) / 2);

        if (check(middle)) { //Need to search through the lower half
            high = middle;
        }

        else { // Need to search through the upper half
            low = middle + 1;
        }
    }

    cout << high << endl;
}