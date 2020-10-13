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

int main()
{

	sublime();
	int n;
	cin >> n;
	int arr[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	stack<int> st;
	st.push(arr[n - 1]);
	int ans[n];
	ans[n - 1] = -1;
	for (int i = n - 2; i >= 0; i--) {
		while (st.size() > 0 && st.top() < arr[i]) {
			st.pop();
		}
		if (st.size() == 0) ans[i] = -1;
		else ans[i] = st.top();
		st.push(arr[i]);
	}
	for (int i = 0; i < n; i++) cout << ans[i] << endl;
	return 0;
}


