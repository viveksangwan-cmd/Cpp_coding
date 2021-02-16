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
void numTilePossibilities(string str, int pos, int count, string ans)
{
	if (pos == str.length()) {
		if (count == 0) {
			cout << ans << endl;
		} else {
			cout << ans + to_string(count) << endl;
		}
		return;
	}
	if (count != 0) {
		numTilePossibilities(str, pos + 1, 0, ans + to_string(count) + str[pos]);
	} else {
		numTilePossibilities(str, pos + 1, 0, ans + str[pos]);
	}
	numTilePossibilities(str, pos + 1, count + 1, ans);
}


int main() {
	sublime();
	string str;
	cin >> str;
	numTilePossibilities(str, 0, 0, "");
	return 0;
}

// input->
// pep



// output->
// pep
// pe1
// p1p
// p2
// 1ep
// 1e1
// 2p
// 3