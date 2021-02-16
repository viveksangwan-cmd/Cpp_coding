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

void solve(int cb, int tb, vector<int> items, int ssf, int ts, string asf) {

	if (cb > tb) {
		if (ssf == ts) {
			cout << asf << endl;
		}
		return;
	}

	for (int i = 0; i < ts; i++) {
		if (items[i] == 0) {
			items[i] = 1;
			solve(cb + 1, tb, items, ssf + 1, ts, asf + to_string(i + 1));
			items[i] = 0;
		}
	}

	solve(cb + 1, tb, items, ssf, ts, asf + to_string(0));

}

int main()
{
	sublime();
	int box, x;
	cin >> box >> x;
	vector<int> arr(x, 0);
	solve(1, box, arr, 0, x, "");

	return 0;
}


