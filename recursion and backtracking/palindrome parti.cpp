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

void solve(int idx, int length, map<char, int> cm, string mid, string sof) {
	if (idx > length) {
		cout << sof << mid;
		for (int i = sof.length() - 1; i >= 0; i--) cout << sof[i];
		cout << endl;
		return;
	}

	for (auto i : cm) {
		int freq = i.second;
		if (freq > 0) {
			cm[i.first] = freq - 1;
			solve(idx + 1, length, cm, mid, sof + i.first);
			cm[i.first] = freq;
		}
	}
}



int main() {
	sublime();
	string a;
	cin >> a;
	map<char, int> cm;
	for (int i = 0; i < a.length(); i++) {
		cm[a[i]]++;
	}

	string mid = "";
	int map_length = 0, count = 0;
	for (auto i = cm.begin(); i != cm.end(); i++) {
		int freq = i->second;
		if (freq % 2 == 1) {
			mid += i->first;
			count++;
		}
		cm[i->first] = freq / 2;
		map_length += freq / 2;
	}

	for (auto i = cm.begin(); i != cm.end(); i++) {
		cout << i->first << " " << i->second << endl;
	}



	if (count > 1) {
		cout << -1 << endl;
	} else {
		solve(1, map_length, cm, mid, "");
	}

}

// aaabb

// a 1
// b 1
// ababa
// baaab
