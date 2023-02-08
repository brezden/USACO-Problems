// Problem: https://codeforces.com/problemset/problem/1560/B
// Solved on January 18th 2023

#include <iostream>
using namespace std;

int main()
{
    int caseAmount, circleAmount, a, b, c, d, r;
   
    cin >> caseAmount;

    int outputValues[100000];

    for (int i = 0; i < caseAmount; i++) {
        cin >> a >> b >> c;

        if (a > b) {
            r = a - b;
        }

        else {
            r = b - a;
        }

        circleAmount = r * 2;

        if (a > circleAmount || b > circleAmount || c > circleAmount) {
            outputValues[i] = -1;
        }

        else {
            
            if (c + r <= circleAmount) {
                outputValues[i] = c + r;
            }

            else if (c-r<=circleAmount&&c-r>0){
                outputValues[i] = c - r;
            }

            else {
                outputValues[i] = -1;
            }
        }
    }

    for (int j = 0; j < caseAmount; j++) {
        cout << outputValues[j] << "\n";
    }
}
