// Problem: https://www.usaco.org/index.php?page=viewproblem2&cpid=668
// Solved on March 14th 2023

#include <iostream>
#include <cstring>
#include <math.h>
#include <vector>

using namespace std;
int xcord[201];
int ycord[201];
int power[201];
bool visited[201];
int n = 0, maxCount = 0, currentCount = 0;
vector<int> bfs;

double cowDistance(int x0, int y0, int x1, int y1){
    return(pow(((pow((x1-x0), 2)) + (pow((y1-y0), 2))), 0.5));
}

//BFS that will check all nodes and the distance and return the max cow count we had
int cowReach(int node){
    memset(visited, false, sizeof(visited)); // Reset for every node
    bfs.clear();
    bfs.push_back(node);
    visited[node] = true;
    currentCount = 1;

    while(bfs.size() > 0){
        // Taking cow from back of list and removing it
        int cow = bfs.back();
        bfs.pop_back();

        for(int i = 0; i < n; i++){
            // Havent seen the node yet
            if(visited[i] == false){
                // Able to reach the node we want to search it
                if (power[cow] >= cowDistance(xcord[cow], ycord[cow], xcord[i], ycord[i])){
                    currentCount++;
                    visited[i] = true;
                    bfs.push_back(i);
                }
            }
        }
    }

    return currentCount;
}

int main(){
    memset(power, 0, sizeof(power));
    memset(xcord, 0, sizeof(xcord));
    memset(ycord, 0, sizeof(ycord));

    cin >> n;

    // Taking input for X, Y, Power
    for (int i = 0; i < n; i++){
        cin >> xcord[i] >> ycord[i] >> power[i];
    }

    // Finding reach of each cow, if its the biggest we have seen set the value to max
    for (int i = 0; i < n; i++){
        maxCount = max(maxCount, cowReach(i));
    }

    cout << maxCount << endl;
}