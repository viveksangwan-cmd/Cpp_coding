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

void solve(int queenPlaced, int n,  int row, int col, string ans) {

	if (row == n) {
		if (queenPlaced == n) {
			cout << ans << endl;
		}
		return;
	}

	int nr = 0;
	int nc = 0;

	string ynew = ans, nnew = ans;
	if (col == n - 1) {
		nr = row + 1;
		nc = 0;
		ynew +=  "q\n";
		nnew += "-\n";
	} else {
		nr = row;
		nc = col + 1;
		ynew += "q";
		nnew += "-";
	}

	solve(queenPlaced + 1, n, nr, nc, ynew);
	solve(queenPlaced + 0, n, nr, nc, nnew);

}


int main() {
	sublime();
	int n;
	cin >> n;
	solve(0, n, 0, 0, "");
}

