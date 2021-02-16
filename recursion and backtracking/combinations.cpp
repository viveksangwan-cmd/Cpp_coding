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
void display(vector<int> arr) {
	for (auto i : arr) {
		if (i == 0)cout << "-";
		else cout << "i";
	}
	cout << endl;
}


void solve(vector<int> arr, int i, int toy, int start) {
	if (toy == 0) {
		display(arr);
		return;
	}
	for (int j = start; j < arr.size(); j++) {
		if (arr[j] == 0) {
			arr[j] = i;
			solve(arr, i + 1, toy - 1, j + 1);
			arr[j] = 0;
		}
	}
}

int main() {
	sublime();

	int box, toy;
	cin >> box >> toy;

	vector<int> arr(box, 0);

	solve(arr, 1, toy, 0);

	return 0;
}

// 5
// 3

// iii--
// ii-i-
// ii--i
// i-ii-
// i-i-i
// i--ii
// -iii-
// -ii-i
// -i-ii
// --iii
