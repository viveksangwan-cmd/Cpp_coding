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

int maxprofit(vector<vector<int>> mine, vector<vector<bool>> &visited,
              int row, int col , int i, int j) {

	if (i < 0 || j < 0 || i == row || j == col ||
	        mine[i][j] == 0 || visited[i][j] == true) return 0;

	visited[i][j] = true;

	int lmine = maxprofit(mine, visited, row, col, i - 1, j);
	int rmine = maxprofit(mine, visited, row, col, i + 1, j);
	int umine = maxprofit(mine, visited, row, col, i, j - 1);
	int dmine = maxprofit(mine, visited, row, col, i, j + 1);
	return mine[i][j] + lmine + rmine + umine + dmine;
}



int main() {
	sublime();
	int n, m;
	cin >> n >> m;
	vector<vector<int>> mine(n, vector<int> (m, 0));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> mine[i][j];
		}
	}

	vector<vector<bool>> visited(n, vector<bool> (m, false));

	int ans = 0, current = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (visited[i][j] == false)
				current = maxprofit(mine, visited, n, m, i, j);
			if (ans < current) ans = current;
		}
	}
	cout << ans;
}


// 6
// 6
// 0 1 4 2 8 2
// 4 3 6 5 0 4
// 1 2 4 1 4 6
// 2 0 7 3 2 2
// 3 1 5 9 2 4
// 2 7 0 8 5 1



// 120
