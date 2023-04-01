// Problem: https://cses.fi/problemset/task/1672/
// Solved on: April 1st 2023

#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;
long long n, m, q;

int main(){
    cin >> n >> m >> q;
    vector<vector<long long>> grid(n + 1, vector<long long>(n + 1, 1e15));

    // Making each distance from city to same city zero
    for (long long i = 1; i <= n; i++){
        grid[i][i] = 0;
    }

    // Adding values to the matrix
    for (long long i = 0; i < m; i++){
        long long a, b, c;
        cin >> a >> b >> c;
        grid[a][b] = min(grid[a][b], c);
        grid[b][a] = min(grid[b][a], c);
    }

    // Going to be using the Floyd-Warshall algorithm
    // We could use dijkstra but it would fail due to the amount 
    // of times we would need to run it.
    for (long long i = 1; i <= n; i++){

        // These two inners loops will add values into
        // the matrix. The outside "i" loop will be used
        // for looking at each city 

        for (long long j = 1; j <= n; j++){
            for (long long k = 1; k <= n; k++){
                // Making sure that both values are not inf
                if ((grid[j][i] != 1e15) && (grid[i][k] != 1e15)){
                    // Checking if we can find a shorter distance
                    grid[j][k] = min(grid[j][k], (grid[j][i] + grid[i][k])); 
                }
            }
        }
    }

    for (long long i = 0; i < q; i++){
        long long d, e;
        cin >> d >> e;
        long long distance = grid[d][e];

        // Checking that the route is possible
        if (distance == 1e15){
            cout << -1 << endl;
        } else {
            cout << distance << endl;
        }
    }
}