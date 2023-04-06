// Problem: https://cses.fi/problemset/task/1666/
// Solved on April 5th 2023

#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <cstring>

using namespace std;
vector<int> cities[200001];
vector<int> componentParents;
bool visited[200001];
int componentCount = 0;

// Simple DFS Search
void dfs(int city){
    visited[city] = true;

    for (int node: cities[city]){
        if (!(visited[node])){
            dfs(node);
        }
    }
}

int main(){
    memset(visited, false, sizeof(visited));

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        cities[a].push_back(b);
        cities[b].push_back(a);
    }

    for (int i = 1; i <= n; i++){
        // If we have not seen the city before we run dfs
        if (!(visited[i])){
            dfs(i);
            // Pushing the parent to the vector so we can find the routes between components  
            componentParents.push_back(i);
            // Increasing the amount of components we have seen
            componentCount++;
        }
    }

    // Outputting the amount of components    
    cout << componentCount - 1 << endl;

    // Outputting the paths we have discovered.
    for (int i = 1; i < componentCount; i++){
        cout << componentParents[i] << " " << componentParents[i - 1] << endl;
    }
}