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

bool correct_comb(string a, string b, string ans, map<char, int> &cm) {
	string anos = "", bnos = "", ansnos = "";
	for (int i = 0; i < a.length(); i++) {
		anos += to_string(cm[a[i]]);
	}
	for (int i = 0; i < b.length(); i++) {
		bnos += to_string(cm[b[i]]);
	}
	for (int i = 0; i < ans.length(); i++) {
		ansnos += to_string(cm[ans[i]]);
	}
	int ano = stoi(anos);
	int bno = stoi(bnos);
	int ansno = stoi(ansnos);
	if ((ano + bno) == ansno) return true;
	else return false;
}


void solve(string unique, int idx, map<char, int> &cm, vector<bool> &intUsed, string a,
           string b, string ans) {
	if (idx == unique.length()) {
		if (correct_comb(a, b, ans, cm)) {
			for (int i = 0; i < 26; i++) {
				char ch = (char)('a' + i);
				if (cm.find(ch) != cm.end()) {
					cout << ch << "-" << cm[ch] << " ";
				}
			}
			cout << endl;
		}
		return;
	}

	for (int i = 0; i <= 9; i++) {
		if (intUsed[i] == false) {
			intUsed[i] = true;
			cm[unique[idx]] = i;
			solve(unique, idx + 1, cm, intUsed, a, b, ans);
			intUsed[i] = false;
			cm[unique[idx]] = -1;
		}
	}

}



int main()
{
	sublime();
	string a, b, ans;
	cin >> a >> b >> ans;

	map<char, int> cm;
	string unique = "";
	for (int i = 0; i < a.length(); i++) {
		if (cm.find(a[i]) == cm.end()) {
			cm[a[i]] = -1;
			unique += a[i];
		}
	}

	for (int i = 0; i < b.length(); i++) {
		if (cm.find(b[i]) == cm.end()) {
			cm[b[i]] = -1;
			unique += b[i];
		}
	}
	for (int i = 0; i < ans.length(); i++) {
		if (cm.find(ans[i]) == cm.end()) {
			cm[ans[i]] = -1;
			unique += ans[i];
		}
	}

	vector<bool> intUsed(9, false);
	solve(unique, 0, cm, intUsed, a, b, ans);
}


// team
// pep
// toppr


// a-3 e-9 m-4 o-1 p-2 r-6 t-0
// a-3 e-9 m-5 o-1 p-2 r-7 t-0
// a-3 e-9 m-6 o-1 p-2 r-8 t-0
// a-4 e-9 m-2 o-1 p-3 r-5 t-0
// a-4 e-9 m-5 o-1 p-3 r-8 t-0
// a-5 e-9 m-2 o-1 p-4 r-6 t-0
// a-5 e-9 m-3 o-1 p-4 r-7 t-0
// a-6 e-9 m-2 o-1 p-5 r-7 t-0
// a-6 e-9 m-3 o-1 p-5 r-8 t-0
// a-7 e-9 m-2 o-1 p-6 r-8 t-0
