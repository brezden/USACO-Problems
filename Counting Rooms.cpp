// Problem: https://cses.fi/problemset/task/1192/
// Solved on March 25th 2023

#include <iostream>
#include <cstring>

using namespace std;

int n, m;
int answer = 0;
int grid[1001][1001];

void dfs(int x, int y){

    grid[x][y] = 1;

    // Right Node
    if (x+1 <= 1000 && y <= 1000 && grid[x+1][y] == 0){
        dfs(x+1, y);
    }

    // Above Node
    if (y+1 <= 1000 && x <= 1000 && grid[x][y+1] == 0){
        dfs(x, y+1);
    }

    // Left Node
    if (x-1 >= 0 && y <= 1000 && grid[x-1][y] == 0){
        dfs(x-1, y);
    }

    // Below Node
    if (y-1 >= 0 && x <= 1000 && grid[x][y-1] == 0){
        dfs(x, y-1);
    }
}

int main(){
    cin >> n >> m;
    memset(grid, 1, sizeof(grid));

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            char a;
            cin >> a;
            if (a == '#'){
                grid[i][j] = 1;
            } else {
                grid[i][j] = 0;
            }
        }
    }

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (grid[i][j] == 0){
                dfs(i, j);
                answer++;
            }
        }
    }

    cout << answer;
}