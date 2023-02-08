// Problem: http://www.usaco.org/index.php?page=viewproblem2&cpid=593
// Solved on February 4th 2023

#include <math.h>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int n;
long x = 9999999;
int currentX, currentY, movement = 0;
int totalTime = 0;

char direction;

int main()
{
    vector<pair<int, int>> coordinates;
    vector<pair<int, int>> seenCoordinates;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> direction >> movement;

        if (direction == 'N') {
            for (int j = 0; j < movement; j++) {
                currentY++;
                seenCoordinates.push_back((make_pair(currentX, currentY)));
            }
        }

        else if (direction == 'E') {
            for (int j = 0; j < movement; j++) {
                currentX++;
                seenCoordinates.push_back(make_pair(currentX, currentY));
            }
        }

        else if (direction == 'S') {
            for (int j = 0; j < movement; j++) {
                currentY--;
                seenCoordinates.push_back(make_pair(currentX, currentY));
            }
        }

        else if (direction == 'W') {
            for (int j = 0; j < movement; j++) {
                currentX--;
                seenCoordinates.push_back(make_pair(currentX, currentY));
            }
        }

        totalTime += movement;
    }
    
    reverse(seenCoordinates.begin(), seenCoordinates.end());

    for (int i = totalTime; i > 0; i--) {
        pair<int, int> tempCords = seenCoordinates.back();
        seenCoordinates.pop_back();

        auto count = find(seenCoordinates.begin(),seenCoordinates.end(), tempCords);

        if (count != seenCoordinates.end()) {
           x = min(x, seenCoordinates.end() - count);
        }
    }

    if (x != 9999999) {
        cout << x << endl;
    }

    else {
        cout << -1 << endl;
    }
}