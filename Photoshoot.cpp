// Problem: http://usaco.org/index.php?page=viewproblem2&cpid=1227
// Solved on February 13th 2023

#include <bits/stdc++.h>

using namespace std;

int counter = 0;
string cow;
char states[200000];

int main(){

    int n;
    char previousState = 'N';
    int counter = 0;
    string cow;
    char states[200000];

    cin >> n;
    cin >> cow;

    //Checking all the pairs in the string
    for (int i = 0; i < n; i += 2){
        
        // Case 1: HG (True)
        if (cow[i] == 'H' && cow[i+1] == 'G'){
            if (previousState != 'T'){
                states[counter] = 'T';
                previousState = 'T';
                counter++;
            }
        }

        // Case 2: GG or HH (Nothing we can do to fix that)
        else if (cow[i] == cow[i+1]){
            continue;
        }

        // Case 3: GH (False)
        else {
            if (previousState != 'F'){
                states[counter] = 'F';
                previousState = 'F';
                counter++;
            }
        }
    }

    //Checking if the end of the states is True.
    // If this is true we dont need to flip it since it is at the end
    if (states[counter - 1] == 'T'){
        cout << counter - 1;
    }

    else{
        cout << counter;
    }
}