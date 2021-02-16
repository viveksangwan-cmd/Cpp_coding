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

int check(string current) {
	stack<char> st;
	for (int i = 0; i < current.length(); i++) {
		if (current[i] == '(') {
			st.push(current[i]);
		} else if (current[i] == ')') {
			if (st.size() == 0) {
				st.push(current[i]);
			} else if (st.top() == '(') {
				st.pop();
			} else {
				st.push(current[i]);
			}
		}
	}
	return st.size();
}

void printValid(string current, int value , set<string> ss) {
	if (value == 0) {
		if (check(current) == 0) {
			if (ss.count(current) == 0) {
				cout << current << endl;
				ss.insert(current);
			}
		}
		return;
	}

	for (int i = 0; i < current.length(); i++) {
		string left = current.substr(0, i);
		string right = current.substr(i + 1);
		printValid(left + right, value - 1, ss);
	}
}


int main() {
	sublime();
	string ques;
	cin >> ques;

	int mini = check(ques);
	set<string> ss;
	printValid(ques, mini, ss);

	return 0;
}