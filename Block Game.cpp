// Problem: http://www.usaco.org/index.php?page=viewproblem2&cpid=664
// Solved on January 31st 2023

#include <bits/stdc++.h>
using namespace std;

string totalWord;
map<char, int> firstBlockCount;
map<char, int> secondBlockCount;
map<char, int> answerCount;
int N;

void resetFirstBlock() {
	for (char i = 'a'; i <= 'z'; i++) {
		firstBlockCount[i] = 0;
	}
}

void resetSecondBlock() {
	for (char i = 'a'; i <= 'z'; i++) {
		secondBlockCount[i] = 0;
	}
}

int main()
{
	cin >> N;
	
	resetFirstBlock();
	resetSecondBlock();
	string word1;
	string word2;

	for (int i = 0; i < N; i++) { // Each set of words
		cin >> word1 >> word2;

		for (int j = 0; j < 2; j++) {
			for (int k = 0; k < word1.length(); k++) {
				firstBlockCount[word1[k]]++;
			}

			for (int k = 0; k < word2.length(); k++) {
				secondBlockCount[word2[k]]++;
			}
		}

		for (char j = 'a'; j <= 'z'; j++) {
			answerCount[j] += max(firstBlockCount[j], secondBlockCount[j]);
		}

		resetFirstBlock();
		resetSecondBlock();
	}

	for (char i = 'a'; i <= 'z'; i++) {
		cout << answerCount[i] / 2 << "\n";
	}
}
