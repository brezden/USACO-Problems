// Problem: https://cses.fi/problemset/task/1674
// Solved on March 19th 2023

#include <iostream>
#include <cstring>
#include <math.h>
#include <algorithm>
#include <vector>

using namespace std;

int n;
vector<int> employee[200001];
int subordinates[200001];

// Recursive algorithm for finding count of subordinates
int dfs(int currEmployee){
    
    // First Case: employee will have sub employees so we 
    // will need to search each one and count the total amount
    // of subordinates
    if (employee[currEmployee].size() != 0){
        for (int subEmployee : employee[currEmployee]){
            int employeeCount = dfs(subEmployee);
            subordinates[currEmployee] += employeeCount;
        }
    } 

    // Second Case: employee will have no subordinates so
    // we just need to return 1 to account for that node
    
    else {
        return 1;
    }

    // Adding ++ since we dont account for the node itself
    return ++subordinates[currEmployee];
}

int main(){
    memset(subordinates, 0, sizeof(subordinates));
    cin >> n;

    // Starting at 2 since we already account for the
    // first employee
    for (int i = 2; i <= n; i++){
        int a;
        cin >> a;
        employee[a].push_back(i);
    }

    dfs(1);

    // Outputting the final subordinates for each employee
    for (int i = 1; i <= n; i++){

        int checker = 0;

        if (subordinates[i] != 0){
            checker = 1;
        }

        // Reason for checker is to remove the node itself since
        // its not a boss of itself
        cout << subordinates[i] - checker << " ";
    }
}