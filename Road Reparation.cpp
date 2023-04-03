// Problem: https://cses.fi/problemset/task/1675
// Solved on April 2nd 2023

#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;
long long n, m;
long long a, b ,c;
long long totalWeight = 0;
long long totalEdges = 0;
long long parentList [200001];
vector<pair<long long , pair<long long, long long>>> adjList;

long long findParent(long long city){
    // If the parent is -1 that means the parent is itself 
	if (parentList[city] == -1){
        return city;
    } else {
        // Recursively finding the parent of the city
        parentList[city] = findParent(parentList[city]);
        return parentList[city];
    }
}

bool merge(long long cityOne, long long cityTwo){
    // Getting both parents of the cities
    long long parentA = findParent(cityOne);
    long long parentB = findParent(cityTwo);

    // If both parents are the same then we cannot merge
    if (parentA == parentB){
        return false;
    } else {
        // Setting the parent to the new parent
        parentList[parentA] = parentB;
        return true; 
    }
}

int main(){
    memset(parentList, -1, sizeof(parentList));
    cin >> n >> m;

    // Taking input from the user in the form of 
    // {Weight, {First Vertex, Second Vertex}}
    for(long long i = 0; i < m; i++){
        cin >> a >> b >> c;
        adjList.push_back({c, {a, b}});
    }

    // Sorting based on the weight of the graph
    sort(adjList.begin(), adjList.end());

    // Kruskal Algo
    for (pair<long long, pair<long long, long long>> city : adjList){
        // If the two vertexs on the city are not both the same parent we merge
        if (merge(city.second.first, city.second.second)){
            // Increasing the total weight by adding the weight of the current city
            totalWeight += city.first;
            // Keeping track of edges for check to see if its a spanning tree
            totalEdges++;
        }
    }

    // If the amount of edges is one less then the amount of cities then we know 
    // a spanning tree is possible
    if (totalEdges == (n-1)){
        cout << totalWeight << endl;
    } else {
        cout << "IMPOSSIBLE" << endl;
    }
}