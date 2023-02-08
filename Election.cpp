// Problem: https://codeforces.com/problemset/problem/1593/A
// Solved on January 16th 2023

#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int testAmount, a, b, c, a1, b1, c1;

    cin >> testAmount;

    for (int i = 0; i < testAmount; i++) {
        cin >> a >> b >> c;

        a1 = (max(b, c) - a) + 1;
        b1 = (max(a, c) - b) + 1;
        c1 = (max(a, b) - c) + 1;

        if (a > b && a > c) {
            a1 = 0;
        }

        if (b > a && b > c) {
            b1 = 0;
        }

        if (c > a && c > b) {
            c1 = 0;
        }

        cout << a1 << " " << b1 << " " << c1 << " " << "\n";

    }
}
