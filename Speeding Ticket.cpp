// Problem: http://www.usaco.org/index.php?page=viewproblem2&cpid=568
// Solved on January 29th 2023

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m;
    int cowRange, cowSpeed;
    int roadRange, roadSpeed;
    int roadSpeeds[100];
    int cowSpeeds[100];
    int maxSpeed = 0;


    cin >> n >> m;

    int totalDistanceTravelled = 1;

    for (int i = 0; i < n; i++) {

        cin >> roadRange >> roadSpeed;

        int x = totalDistanceTravelled + roadRange;

        for (int j = totalDistanceTravelled; j < x; j++) {
            roadSpeeds[j] = roadSpeed;
        }

        totalDistanceTravelled += roadRange;
    }

    totalDistanceTravelled = 1;

    for (int i = 0; i < m; i++) {

        cin >> cowRange >> cowSpeed;

        int x = totalDistanceTravelled + cowRange;

        for (int j = totalDistanceTravelled; j < x; j++) {
            cowSpeeds[j] = cowSpeed;
        }

        totalDistanceTravelled += cowRange;
    }

    for (int i = 1; i < 101; i++) {
        int y = cowSpeeds[i] - roadSpeeds[i];
        maxSpeed = max(maxSpeed, y);
    }

    cout << maxSpeed << endl;
}

