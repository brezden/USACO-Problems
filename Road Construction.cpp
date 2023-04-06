// Problem: https://cses.fi/problemset/task/1676/
// Solved on April 2nd 2023

#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;
long long n, m;
long long a, b;
int maxComp = 0;
long long totalComp = 0;
long long parentList [200001];
int totalNodes [200001];

vector<pair<int, int>> adjList;
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
        // Adding the previous component count to the new parent
        totalNodes[parentB] += totalNodes[parentA];
        return true; 
    }
}

int main(){
    memset(parentList, -1, sizeof(parentList));

    // Memset wasnt working for some reason ?
    for(int i = 0; i < 200001; i++){
        totalNodes[i] = 1;
    }

    cin >> n >> m;

    totalComp = n;

    for(long long i = 0; i < m; i++){
        cin >> a >> b;
        adjList.push_back({a, b});

        // Checking if we can merge the two nodes
        if (merge(a, b)){
            // We check to see if we have a new max component
            maxComp = max(maxComp, totalNodes[findParent(b)]);
            // If we merged two components then that means we have one less component
            totalComp--;
        }

        cout << totalComp << " " << maxComp << endl;
    }
}