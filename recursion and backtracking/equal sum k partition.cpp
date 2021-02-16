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

void display(vector<vector<int>> ans, int k) {
	for (int i = 0; i < k; i++) {
		cout << '[';
		for (int j = 0; j < ans[i].size() - 1; j++) {
			cout << ans[i][j] << ", ";
		}
		cout << ans[i][ans[i].size() - 1] << "] ";
	}
	cout << endl;
}

void solve(int start, int level, int n, int k, vector<int> arr, vector<vector<int>> ans, vector<int> total) {
	if (start == n) {
		if (level == k) {
			bool t = true;
			for (int i = 0; i < k - 1; i++) {
				if (total[i] != total[i + 1]) {
					t = false;
				}
			}
			if (t) {
				display(ans, k);
			}
		}
		return;
	}

	for (int i = 0; i < k; i++) {
		if (ans[i].size() > 0) {
			total[i] += arr[start];
			ans[i].push_back(arr[start]);
			solve(start + 1, level, n, k, arr, ans, total);
			total[i] -= arr[start];
			ans[i].pop_back();
		} else {
			total[i] += arr[start];
			ans[i].push_back(arr[start]);
			solve(start + 1, level + 1, n, k, arr, ans, total);
			total[i] -= arr[start];
			ans[i].pop_back();
			break;
		}
	}
}


int main() {
	sublime();
	int n;
	cin >> n;

	vector<int> arr(n);
	for (int i = 0; i < n; i++) cin >> arr[i];

	int k;
	cin >> k;

	vector<vector<int>> ans(k);
	vector<int> total(k, 0);

	solve(0, 0, n, k, arr, ans, total);

	return 0;
}

// 9
// 3
// 1
// 7
// 6
// 5
// 11
// 9
// 10
// 2
// 3

// [3, 1, 5, 9] [7, 11] [6, 10, 2]
// [3, 6, 9] [1, 7, 10] [5, 11, 2]
// [3, 6, 9] [1, 5, 10, 2] [7, 11]
// [3, 5, 10] [1, 6, 11] [7, 9, 2]
// [3, 5, 10] [1, 6, 9, 2] [7, 11]
