// Problem: http://www.usaco.org/index.php?page=viewproblem2&cpid=944
// Solved on March 15th 2023

#include <iostream>
#include <cstring>
#include <math.h>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int n, m, a, b;
int answer = 1e9;
int xcords[100001];
int ycords[100001];
bool visited[100001];
vector<int> adjlist[100001];
vector<int> dfs [100001];

int main(){

    cin >> n >> m;
    memset(visited, false, sizeof(visited));

    // Taking in X and Y Cords
    for (int i = 1; i <= n; i++){
        cin >> xcords[i] >> ycords[i];
    }

    // Making adjacency list for connections between cows
    for (int i = 0; i < m; i++){
        cin >> a >> b;
        adjlist[a].push_back(b);
        adjlist[b].push_back(a);
    }

    for (int i = 1; i <= n; i++){
        // If we have not visited this cow
        if (!visited[i]){
            int minX = 1e8; int maxX = 0; int minY = 1e8; int maxY = 0;
            queue<int> dfs; // Queue for DFS
            dfs.push(i);

            // DFS Search for cow groups
            while (!dfs.empty()){
                int node = dfs.front();
                dfs.pop();
                for (int cow : adjlist[node]){
                    if (!visited[cow]){
                        dfs.push(cow);
                        visited[cow] = true;
                    }
                }

                // After each search we need to check the min/max values 
                minX = min(minX, xcords[node]);
                maxX = max(maxX, xcords[node]);
                minY = min(minY, ycords[node]);
                maxY = max(maxY, ycords[node]);
            }

            // Checking if we have seen a smaller perimeter before
            answer = min(answer, ((2 * (maxX - minX)) + (2 * (maxY - minY))));
        }
    }

    cout << answer << endl;
}