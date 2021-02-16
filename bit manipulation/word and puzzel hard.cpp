#include <bits/stdc++.h>
#define int long long
using namespace std;

void sublime()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}


vector<int> solve(vector<string> words, vector<string> puzzels) {
	vector<int> ans;

	map<char, vector<int>> WordMap;
	for (int i = 0; i < 26; i++) {
		WordMap[(char)('a' + i)] = {};
	}

	for (auto word : words) {
		int mask = 0;
		for (int i = 0; i < word.length(); i++) {
			int z = word[i] - 'a';
			mask |= (1 << z);
		}

		set<char> char_set;
		for (int i = 0; i < word.length(); i++) {
			if (char_set.find(word[i]) != char_set.end()) {
				continue;
			}
			WordMap[word[i]].push_back(mask);
			char_set.insert(word[i]);
		}
	}

	for (auto puzzle : puzzels) {
		int pmask = 0;
		for (int i = 0; i < puzzle.length(); i++) {
			int z = (puzzle[i] - 'a');
			pmask |= (1 << z);
		}

		vector<int> current_match = WordMap[puzzle[0]];
		int count = 0;
		for (auto i : current_match) {
			if ((i & pmask) == i) {
				count++;
			}
		}
		ans.push_back(count);
	}

	return ans;
}

int32_t main() {
	sublime();

	int n; cin >> n;
	vector<string> words(n);
	for (int i = 0; i < n; i++) {
		cin >> words[i];
	}

	int p; cin >> p;
	vector<string> puzzels(p);
	for (int i = 0; i < p; i++) {
		cin >> puzzels[i];
	}

	vector<int> ans = solve(words, puzzels);
	for (auto i : ans) cout << i << " ";
}