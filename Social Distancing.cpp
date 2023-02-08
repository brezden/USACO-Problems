// Problem: http://www.usaco.org/index.php?page=viewproblem2&cpid=1038
// Solved on January 24th 2023

#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <math.h>

using namespace std;

int n, m;
pair<long long, long long> intervals[100001];

bool check(long long d) {
    long long current = intervals[0].first;
    int currentInterval = 0;
    
    for (int i = 1; i < n; i++) {
        current += d;
        //Incrementing the interval until it reaches the next one
        while (currentInterval < m && current > intervals[currentInterval].second) {
            currentInterval++;
        }

        if (currentInterval == m) {
            return false;
        }

        if (intervals[currentInterval].first > current) {
            current = intervals[currentInterval].first;
        }
    }

    return true;
}

int main()
{   
    freopen("socdist.in", "r", stdin);
    freopen("socdist.out", "w", stdout);


    //Taking in n and m
    cin >> n >> m;

    //Adding the intervals into the pair variable
    for (int i = 0; i < m; i++) {
        cin >> intervals[i].first >> intervals[i].second;
    }

    //Sort the intervals in increasing order
    sort(intervals, intervals + m);

    //Set the low and high variables
    long long low = 1;
    long long high = pow(10, 18);

    //Using binary search and the check function
    while (low + 1 < high) {
        long long middle = (low + high) / 2;
        if (check(middle)) {
            low = middle;
        }
        else {
            high = middle;
        }
    }

    cout << low << endl;
}
