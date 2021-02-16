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

void display(map<char, string> csm) {
	for (auto i : csm) {
		cout << i.first << " " << i.second << endl;
	}
}

void solve(string str, string pattern, map<char, string> csm, string op) {

	if (pattern.length() == 0) {
		if (str.length() == 0) {
			cout << op + "." << endl;
		}
		return;
	}

//	cout << str << " " << pattern << endl;

	char currentChar = pattern[0]; 0
	string leftPattern = pattern.substr(1);

	if (csm.find(currentChar) != csm.end()) {
		string found = csm[currentChar];
		if (found.length() >= str.length()) {
			for (int i = 0; i < found.length(); i++) {
				if (str[i] != found[i]) return;
			}
		}
		string leftString = str.substr(found.length());
		solve(leftString, leftPattern, csm, op);
	} else {
		for (int i = 0; i < str.length(); i++) {
			string currentString = str.substr(0, i + 1);
			csm[currentChar] = currentString;
			string leftString = str.substr(i + 1);
			solve(leftString, leftPattern, csm, op + currentChar + "->" + currentString + ",");
			csm.erase(currentChar);
		}
	}
}


int main() {
	sublime();
	string str, pattern;
	cin >> str >> pattern;


	map<char, string> csm;
	solve(str, pattern, csm, "");

	return 0;
}
