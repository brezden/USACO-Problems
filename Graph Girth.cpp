// Problem: https://cses.fi/problemset/task/1707
// Solved on March 30th 2023

#include <iostream>
#include <cstring>
#include <math.h>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int n, m;
vector<int> adjList[2501];

int CycleFinder(int Node) {

	int shortestCycle = 1000000;
	int distanceForNode[2501];
    memset(distanceForNode, -1, sizeof(distanceForNode));
    distanceForNode[Node] = 0;
    queue<int> bfs;
	bfs.push(Node);

	while (!bfs.empty()) {

		int node = bfs.front();
		bfs.pop();

		for (int AdjacentNode : adjList[node]) {

            // Node has not been seen before (Distance is negative 1)
			if (distanceForNode[AdjacentNode] == -1) {

                // Add current distance to the node we came from
				distanceForNode[AdjacentNode] = distanceForNode[node] + 1;
				bfs.push(AdjacentNode);

            // If the adjacent node distance is the greater or equal to the node we
            // are at then we know we have found a cycle.
			} else if (!(distanceForNode[AdjacentNode] < distanceForNode[node])) {
                // Adding the current distance of the node and the adjacent node plus one for the first parent node. 
				shortestCycle = min(shortestCycle, (1 + distanceForNode[node] + distanceForNode[AdjacentNode]));
			}
		}
	}
	return shortestCycle;
}

int main(){

    int answer = 1000000;

    cin >> n >> m;

    // Creating Adjacency List
    for (int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        adjList[a].push_back(b);
        adjList[b].push_back(a);
    }

    // Calculating cycle for every node
    for (int i = 1; i <= n; i++){
        // Checking if we have seen a smaller cycle to this point
        answer = min(answer, CycleFinder(i));
    }

    // No cycle was found if we the minimum is still 1000000
    if (answer == 1000000){
        cout << -1;
    } else {
        cout << answer;
    }
}