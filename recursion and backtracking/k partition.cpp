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


int countI = 0;
void display(vector<vector<int>> parti, int n, int k) {
	countI++;
	cout << countI << ".";
	for (int i = 0; i < k; i++) {
		cout << "[";
		for (int j = 0; j < parti[i].size() - 1; j++) {
			cout << parti[i][j] << ",";
		}
		cout << parti[i][parti[i].size() - 1] << "]";
	}
	cout << endl;
}

void solve(int start, int level, int n, int k, vector<vector<int>> parti) {
	if (start > n) {
		if (level == k) {
			display(parti, n, k);
		}
		return;
	}
	for (int i = 0; i < k; i++) {
		if (parti[i].size() > 0) {
			parti[i].push_back(start);
			solve(start + 1, level, n, k, parti);
			parti[i].pop_back();
		} else {
			parti[i].push_back(start);
			solve(start + 1, level + 1, n, k, parti);
			parti[i].pop_back();
			break;
		}
	}
}



int main() {
	sublime();
	int n, k;
	cin >> n >> k;
	vector<vector<int>> parti(k);
	solve(1, 0, n, k, parti);
}

//  K partitions of no n with no combination
// 3
// 2

// 1.[1,2][3]
// 2.[1,3][2]
// 3.[1][2,3]
