#include <bits/stdc++.h>
using namespace std;

void sublime()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.TXT", "r", stdin);
	freopen("output.TXT", "w", stdout);
#endif
}

class node {
public:
	char c;
	unordered_map<char, node*> hm;
	bool isTerminal;

	node(char d) {
		c = d;
		isTerminal = false;
	}
};


class trie {
	node* root;
public:
	trie() {
		root = new node('\0');
	}

	// adding a word to trie
	void addWord(char *word) {
		node* temp = root;
		for (int i = 0; word[i] != '\0'; i++) {
			char current = word[i];
			if (temp->hm.count(current) == 0) {
				node *child = new node(current);
				temp->hm[current] = child;
				temp = child;
			} else {
				temp = temp->hm[current];
			}
		}
		temp->isTerminal = true;
	}


	// searching for a word in a trie
	bool search(char* word) {
		node* temp = root;
		for (int i = 0; word[i] != '\0'; i++) {
			char current = word[i];
			if (temp->hm.count(current) == 0) return false;
			else {
				temp = temp->hm[current];
			}
		}
		return temp->isTerminal;
	}

};


int main() {
	sublime();
	trie node;
	char words[5][1000] = {"apple", "appe", "appy", "aayush", "vivek"};
	for (int i = 0; i < 5; i++) {
		node.addWord(words[i]);
	}

	cout << "done inserting " << endl;
	char searchword[100];
	cin.getline(searchword, 100);
	if (node.search(searchword)) {
		cout << "found" << endl;
	} else {
		cout << "not found";
	}

	return 0;
}
