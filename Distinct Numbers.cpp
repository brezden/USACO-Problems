// Problem: https://cses.fi/problemset/task/1621
// Solved on January 20th 2023

#include<iostream>
#include<set>
using namespace std;

int main() {
    int n;
    int x;
    int answer = 0;
    
    cin >> n;

    set<int> s;

    for (int i = 0; i < n; i++) {
        cin >> x;
        s.insert(x);
    }

    cout << s.size();
}