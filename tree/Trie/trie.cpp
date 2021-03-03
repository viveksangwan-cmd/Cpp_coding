#include <bits/stdc++.h>
#define int long long
#define	mod	1000000007
#define endl '\n'
using namespace std;

void sublime()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}

class node{
public:
	char data;
	unordered_map<char,node*> m;
	int isTerminal;

	node(char current){
		data = current;
		isTerminal = 0;
	}
};

class Trie{
	node* root;
public:
	Trie(){
		root = new node('\0');
	}

	// Insertion
	void addWord(string word){
		node* temp = root;
		for(int i=0;i<word.length();i++){
			char current = word[i];
			if(temp->m.count(current)){
				temp = temp->m[current];
			}else{
				node* newNode = new node(current);
				temp->m[current] = newNode;
				temp = newNode;
			}
		}
		temp->isTerminal += 1;
	}

	// Deletion
	void deleteWord(string word){
		node* temp = root;
		for(int i=0;i<word.length();i++){
			char current = word[i];
			if(temp->m.count(current)){
				temp = temp->m[current];
			}else{
				return;
			}
		}
		if(temp->isTerminal>0){
			temp->isTerminal-=1;
		}
	}

	// Searching
	bool search(string word){
		node* temp = root;
		for(int i=0;i<word.length();i++){
			char current = word[i];
			if(temp->m.count(current)){
				temp = temp->m[current];
			}else{
				return false;
			}
		}
		return temp->isTerminal;
	}

};



int32_t main() {
	sublime();

	Trie t;

	int n;
	cin>>n;

	string s;
	for(int i=0;i<n;i++){
		cin>>s;
		t.addWord(s);
	}


	int q;
	cin>>q;
	for(int i=0;i<q;i++){
		cin>>s;
		t.deleteWord(s);
	}

	cin>>q;
	for(int i=0;i<q;i++){
		cin>>s;
		if(t.search(s)){
			cout<<"Found"<<endl;
		}else{
			cout<<"Not Found"<<endl;
		}
	}
}
