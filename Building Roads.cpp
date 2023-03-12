// Problem: https://cses.fi/problemset/task/1666
// Solved on March 12th 2023

#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

vector<vector<int>> CityConnection(200000);
vector<int> CityRoad;
bool CityVisited[200000];

// Depth First Search algo
void dfs(int node){
    CityVisited[node] = true;
    for (int i = 0; i < (int) CityConnection[node].size(); i++){
        int value = CityConnection[node][i];
        if (CityVisited[value] == false){
            dfs(value);
        }
    }
}

int main(){

    int n, m, a, b;
    cin >> n >> m;
    
    memset(CityVisited, false, sizeof(CityVisited));

    // Creating adjacency list for each connection given 
    for (int i = 0; i < m; i++){
        cin >> a >> b;
        CityConnection[a].push_back(b);
        CityConnection[b].push_back(a);
    }
    
    // Searching through the cities
    for (int i = 1; i <= n; i++){
        if (CityVisited[i] == false){
            CityRoad.push_back(i);
            dfs(i);       
        }       
    }

    // Removing first city from the size since it doesnt matter
    cout << CityRoad.size() - 1 << endl;

    // Printing all the possible bridges between cities required
    for (int i = 1; i <= CityRoad.size() - 1; i++){
        cout << CityRoad[i-1] << " " << CityRoad[i] << endl;
    }
}