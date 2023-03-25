// Problem: https://cses.fi/problemset/task/1667
// Solved on March 19th 2023

#include <iostream>
#include <cstring>
#include <math.h>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int n, m;
vector<int> noderoutes[200001];
bool visited[200001];
int parent[200001];

// BFS Algo
void bfs(int node){
    queue<int> nodes;

    visited[node] = true;
    nodes.push(node);

    while(!nodes.empty()){
        int currentNode = nodes.front();
        nodes.pop();

        for(int adjacentNode : noderoutes[currentNode]){
            if(!visited[adjacentNode]){
                visited[adjacentNode] = true;
                nodes.push(adjacentNode);
                // Saving the parent node for the node we have seen
                // We can use this to find the shortest path
                parent[adjacentNode] = currentNode;
            }
        }
    }
}

int main(){
    memset(visited, false, sizeof(visited));
    memset(parent, 0, sizeof(parent));

    cin >> n >> m;

    // Input
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        noderoutes[a].push_back(b);
        noderoutes[b].push_back(a);
    }

    bfs(1);

    // Checking if the route was possible
    if (visited[n] == false){
        cout << "IMPOSSIBLE";
        return 0;
    }


    // Starting from end node
    int currentNode = n;
    vector<int> path;

    // Going back from the end node until we hit 0 (End)
    while (currentNode != 0){
        path.push_back(currentNode);
        // Setting next node to be the parent of current node
        currentNode = parent[currentNode];
    }

    // Need to reverse order
    reverse(path.begin(), path.end());

    // Printing size for the path
    cout << path.size() << endl;

    // Outputting the path
    for (int node : path){
        cout << node << " ";
    }
}