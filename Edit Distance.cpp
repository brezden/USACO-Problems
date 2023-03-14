// Problem: https://cses.fi/problemset/task/1639
// Solved on March 10th 2023

#include <iostream>
#include <cstring>

using namespace std;
int dpTable[5002][5002];

int main(){
    memset(dpTable, 0, sizeof(dpTable));

    string word1, word2;
    cin >> word1;
    cin >> word2;

    for (int i = 0; i <= word1.length(); i++){
        dpTable[i][0] = i;
    }

    for (int i = 0; i <= word2.length(); i++){
        dpTable[0][i] = i;
    }
    
    // This DP Table will take on a specific order of values
    // | Same Value |  Insert  |
    // |   Delete   | (Current)|
    // We will use to scan for the minimum value and add one to the operation

    for (int i = 1; i <= word1.length(); i++){
        for (int j = 1; j <= word2.length(); j++){

            // First Case: This will run if the two characters are the same.
            //             We wont need to add any operation for this case so
            //             this grid slot will take the top left value

            if (word1[i-1] == word2[j-1]){
                dpTable[i][j] = dpTable[i-1][j-1];
            }

            // Second Case: This will run if the two characters are not the same.
            //              We will take the minimum value from the three adjacent
            //              cells and add one (operation) onto it.

            else {
                int topLeft = dpTable[i-1][j-1];
                int topRight = dpTable[i][j-1];
                int bottomLeft = dpTable[i-1][j];
                
                dpTable[i][j] = (min(min(topLeft, topRight), bottomLeft) + 1);
            }
        }
    }

    // The value in the bottom right slot will be the amount of operations
    // it takes to transform the word.
    cout << dpTable[word1.length()][word2.length()];
}