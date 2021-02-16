/*   Vivek Sangwan
	Poornima University */

#include<bits/stdc++.h>
using namespace std;

void sublime()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.TXT", "r", stdin);
	freopen("output.TXT", "w", stdout);
#endif
}


void solve(int qsf, int n, vector<vector<int>> chess, string ans)
{

	if ( qsf == n) {
		if (qsf == n) {
			for (auto i : chess) {
				for (auto j : i) {
					if (j != 0) cout << "q" << j << "\t";
					else cout << "-\t";
				}
				cout << endl;
			}
			cout << endl;
		}
		return;
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (chess[i][j] == 0) {
				chess[i][j] = qsf + 1;
				solve(qsf + 1, n, chess, ans);
				chess[i][j] = 0;
			}
		}
	}
}

int main() {
	sublime();
	int n;
	cin >> n;

	vector<vector<int>> chess(n, vector<int>(n, 0));

	solve(0, n, chess,  "");

}

