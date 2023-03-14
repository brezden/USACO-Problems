// Problem: http://www.usaco.org/index.php?page=viewproblem2&cpid=894
// Solved on March 12th 2023

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
int field[100001];

int main(){
    memset(field, 0, sizeof(field));

    int n, a, b;
    int answer = 0;

    cin >> n;

    // Taking in edge count
    for(int i = 0; i < (n-1); i++){
        cin >> a >> b;
        field[a]++;
        field[b]++;
    }

    // Finding max edge
    for (int i = 1; i <= n; i++){
        if (field[i] > answer) answer = field[i];
    }

    cout << ++answer;
}