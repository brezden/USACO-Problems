// Problem: https://codeforces.com/problemset/problem/1514/C
// Solved on January 17th 2023

#include <iostream>
using namespace std;

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main()
{
    int n;

    cin >> n;

    int solution[200000];

    long sum = 1;
    int length = 0;

    for (int i = 1; i < n; i++){
        if (gcd(i, n) == 1){
            solution[i] = 1;
            sum = sum * i % n;
            length++;
        }
    }

    if (sum != 1){
        length--;
        solution[sum] = 0;
    }

    // Length of the array
    cout << length << "\n";

    // Printing contents of the array
    for (int i = 1; i < n; i++){
        if (solution[i]) cout << i << " ";
    }
}