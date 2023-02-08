// Problem: http://www.usaco.org/index.php?page=viewproblem2&cpid=663
// Solved on January 13 2023

#include <iostream>
using namespace std;

int main()
{
    int ax1, ay1, ax2, ay2;
    int bx1, by1, bx2, by2;

    cin >> ax1 >> ay1 >> ax2 >> ay2;
    cin >> bx1 >> by1 >> bx2 >> by2;

    int maxy = max(ay2, by2);
    int miny = min(ay1, by1);

    int maxx = max(ax2, bx2);
    int minx = min(ax1, bx1);

    int side1 = maxy - miny;
    int side2 = maxx - minx;

    int answer = max(side1 * side1, side2 * side2);

    cout << answer;
}
