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

int solve(vector<string> vs, vector<int> charfrq, vector<int> charValue,
          int idx) {

	if (idx == vs.size()) return 0;


	int no = solve(vs, charfrq, charValue, idx + 1);
	string current = vs[idx];
	int substr_sum = 0;
	bool complete = true;
	for (int i = 0; i < current.length(); i++) {
		char ch = current[i];
		if (charfrq[ch - 'a'] == 0) {
			complete = false;
		}
		charfrq[ch - 'a']--;
		substr_sum += charValue[ch - 'a'];
	}
	int yes = 0;
	if (complete) {
		yes = substr_sum  + solve(vs, charfrq, charValue, idx + 1);
	}
	for (int i = 0; i < current.length(); i++) {
		char ch = current[i];
		charValue[ch - 'a']++;
	}

	return max(yes, no);
}


int main() {
	sublime();
	int n;
	cin >> n;
	vector<string> sv(n);
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		sv[i] = str;
	}

	int totalChar;
	cin >> totalChar;

	vector<int> charfrq(26, 0);
	for (int i = 0; i < totalChar; i++) {
		char current;
		cin >> current;
		charfrq[current - 'a']++;
	}

	vector<int>  charValue(26);
	for (int i = 0; i < 26; i++) {
		cin >> charValue[i];
	}
	cout << solve(sv, charfrq, charValue, 0);
}


// 4
// dog cat dad good
// 9
// a b c d d d g o o
// 1 0 9 5 0 0 3 0 0 0 0 0 0 0 2 0 0 0 0 0 0 0 0 0 0 0


// output
// 23
