// Problem: http://www.usaco.org/index.php?page=viewproblem2&cpid=940
// Solved on March 13th 2023

#include <iostream>
#include <cstring>


using namespace std;
int stationsIn[102];
int stationsOut[102];

int main(){

    memset(stationsIn, 0, sizeof(stationsIn));
    memset(stationsOut, 0, sizeof(stationsOut));
    
    int n;
    cin >> n;

    for (int i = 1; i < n; i++){
        int a, b;
        cin >> a >> b;
        stationsOut[a]++; 
        stationsIn[b]++;
    }

    int maxValue = n-1;
    int counter = 0; // Amount of dead end nodes
    int answer = -1;

    for (int j = 1; j <= n; j++){

        // Checking for a dead end node (Nothing coming out)
        if ((stationsIn[j] > 0) && (stationsOut[j] == 0)){
            // If we have encountered a dead end node then we know it is impossible
            if (counter >= 1){
                answer = -1;
            } 
            
            // Increase the counter of dead end node and the answer is the current node
            else {
                counter++;
                answer = j;
            }
        }
    }

    cout << answer << endl;
}