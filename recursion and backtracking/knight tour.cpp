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

void display(vector<vector<int>> &arr, int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;

}


void knithtour(vector<vector<int>> &arr, int n, int i, int j, int start) {
	if (i < 0 || j < 0 || i >= n || j >= n || arr[i][j] > 0) return;
	if (start == n * n) {
		arr[i][j] = start;
		display(arr, n);
		arr[i][j] = 0;
		return;
	}

	arr[i][j] = start;
	knithtour(arr, n, i - 2, j + 1, start + 1);
	knithtour(arr, n, i - 1, j + 2, start + 1);
	knithtour(arr, n, i + 1, j + 2, start + 1);
	knithtour(arr, n, i + 2, j + 1, start + 1);
	knithtour(arr, n, i + 2, j - 1, start + 1);
	knithtour(arr, n, i + 1, j - 2, start + 1);
	knithtour(arr, n, i - 1, j - 2, start + 1);
	knithtour(arr, n, i - 2, j - 1, start + 1);
	arr[i][j] = 0;
}

int main() {
	sublime();
	int n;
	cin >> n;
	vector<vector<int>> arr(n, vector<int> (n, 0));
	int i, j ;
	cin >> i >> j;
	knithtour(arr, n, i, j, 1);

	return 0;
}