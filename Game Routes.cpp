// Problem: https://cses.fi/problemset/task/1681
// Solved on April 8th 2023

#include <iostream>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;

vector<int> courseList[200001];
vector<int> finished;
queue<int> curr;
int inDegree[200001];
int n, m;

void search(int node){

    // Any course that is not required to complete before another then we can search it
    for(int i = 1; i <= n; i++){
        if (inDegree[i] == 0){
            curr.push(i);
        }
    }

    while (!curr.empty()){
        int currentNode = curr.front();
        curr.pop();
        finished.push_back(currentNode);

        for (int Node : courseList[currentNode]){
            inDegree[Node]--;

            // If we have covered the prereqs for the course then we push it to the queue to check if
            // the course has any prereqs for itself
            if (inDegree[Node] == 0){
                curr.push(Node);
            }
        }
    }
}

int main(){
    cin >> n >> m;
    memset(inDegree, 0, sizeof(inDegree));

    for (int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        courseList[a].push_back(b);
        // Increasing the amount of in degrees for the course
        inDegree[b]++;
    }

    // Running Search
    search(1);

    // If the size of courses is the amount of total courses then its possible
    if (finished.size() == n){
        for (int course : finished){
            cout << course << " ";
        }
    } else {
        cout << "IMPOSSIBLE" << endl;
    }
}
