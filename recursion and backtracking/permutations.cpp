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
	for (auto i : arr) cout << i;
	cout << endl;
}


void solve(vector<int> arr, int i, int toy) {
	if (toy == 0) {
		display(arr);
		return;
	}
	for (int j = 0; j < arr.size(); j++) {
		if (arr[j] == 0) {
			arr[j] = i;
			solve(arr, i + 1, toy - 1);
			arr[j] = 0;
		}
	}
}

int main() {
	sublime();

	int box, toy;
	cin >> box >> toy;

	vector<int> arr(box, 0);

	solve(arr, 1, toy);

	return 0;
}

// 5
// 3

// 12300
// 12030
// 12003
// 13200
// 10230
// 10203
// 13020
// 10320
// 10023
// 13002
// 10302
// 10032
// 21300
// 21030
// 21003
// 31200
// 01230
// 01203
// 31020
// 01320
// 01023
// 31002
// 01302
// 01032
// 23100
// 20130
// 20103
// 32100
// 02130
// 02103
// 30120
// 03120
// 00123
// 30102
// 03102
// 00132
// 23010
// 20310
// 20013
// 32010
// 02310
// 02013
// 30210
// 03210
// 00213
// 30012
// 03012
// 00312
// 23001
// 20301
// 20031
// 32001
// 02301
// 02031
// 30201
// 03201
// 00231
// 30021
// 03021
// 00321
