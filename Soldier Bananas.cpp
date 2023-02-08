// Problem: https://codeforces.com/problemset/problem/546/A
// Solved on January 13th 2023

#include <iostream>
using namespace std;

int main()
{
    int costBanana, soldierMoney, bananaAmount;

    cin >> costBanana >> soldierMoney >> bananaAmount;

    int totalAmount = 0;

    for (int i = 1; i <= bananaAmount; i++) {
        totalAmount += (i * costBanana);
    }

    if (totalAmount - soldierMoney < 0) {
        cout << 0;
    }

    else {
        cout << totalAmount - soldierMoney;
    }
}
