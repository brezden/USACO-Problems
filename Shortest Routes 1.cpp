// Problem: https://cses.fi/problemset/task/1671/
// Solved on March 30th 2023

#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <cstring>
#include <queue>

using namespace std;

long long n, m;
vector<vector<pair<long long, long long>>> adjList;
long long distances[100001];
bool visited[100001];

void DijkstrasAlgo(){
    priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> PQ;
    PQ.push({0, 1});
    // First city to First City will always be zero so we can set it here.
    distances[1] = 0;
 
    while (!PQ.empty()){
        long long node = PQ.top().second;
        PQ.pop();

        if (!visited[node]){
            visited[node] = true;

            // Searching each child in the adj list
            for (auto child : adjList[node]){
                long long next = child.first;
                long long nextDistance = child.second;
                // Possible distance is current distance and distance for child
                long long possibleDistance = distances[node] + nextDistance;

                // If this is smaller then the current distance then we need to update it
                if (possibleDistance < distances[next]){
                    distances[next] = possibleDistance;
                    PQ.push({distances[next], next});
                }
            }
        }
    }
}

int main(){
    long long a, b, c;
    cin >> n >> m;
    adjList.resize(n + 1);
    memset(distances, 1000000, sizeof(distances));

    for (long long i = 0; i < m; i++) {
        cin >> a >> b >> c;
        // One way so we wont need to push [b].push_back({a,c})
        adjList[a].push_back({b, c});
    }

    DijkstrasAlgo();

    // After running Dijkstra we will have all the minimum distances
    // for each node so we just need to prlong long them.
    for (long long i = 1; i <= n; i++){
        cout << distances[i] << " ";
    }
}