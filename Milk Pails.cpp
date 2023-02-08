// Problem: http://www.usaco.org/index.php?page=viewproblem2&cpid=615
// Solved on January 29th 2023

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int x, y, m;
    int maxX, maxY;
    int currentX, currentY;
    int maxAmount = 0;

    cin >> x >> y >> m;

    maxX = floor(m / x);
    maxY = floor(m / y);

    for (int i = 0; i <= maxX; i++) {
        currentX = i * x;

        for (int j = 1; j <= maxY; j++) {
            currentY = j * y;

            if ((currentX + currentY) <= m) {
                maxAmount = max(maxAmount, (currentX + currentY));
            }
        }
    }

    //Missing the case where "Pale X" can be the biggest amount by itself.
    if ((maxX * x) <= m) {
        maxAmount = max(maxAmount, (maxX * x));
    }

    cout << maxAmount << endl;
}
