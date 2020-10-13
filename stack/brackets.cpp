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

bool check(string a)
{
	stack<char> st;
	for (int i = 0; i < a.size(); i++)
	{
		if (a[i] == '(' || a[i] == '{' || a[i] == '[')
		{
			st.push(a[i]);
		}
		else if (a[i] == ')' || a[i] == '}' || a[i] == ']')
		{
			if (a[i] == ')')
			{
				while ( st.size() > 0 && st.top() != '(') {
					st.pop();
				}
				if (st.size() == 0) return false;
				else if (st.size() != 0 && st.top() == '(') st.pop();
				else return false;
			}
			else if (a[i] == '}')
			{
				while (st.size() > 0 && st.top() != '{') {
					st.pop();
				}
				if (st.size() == 0) return false;
				if (st.size() != 0 && st.top() == '{') st.pop();
				else return false;
			}
			else if (a[i] == ']')
			{
				while (st.size() > 0 && st.top() != '[') {
					st.pop();
				}
				if (st.size() == 0) return false;
				if (st.size() != 0 && st.top() == '[') st.pop();
				else return false;
			}
		}
		else continue;
	}
	if (st.size() > 0) return false;
	return true;
}




int main()
{

	sublime();
	string a;
	getline(cin, a);
	bool t = check(a);
	if (t) cout << "true";
	else cout << "false";
	return 0;
}


