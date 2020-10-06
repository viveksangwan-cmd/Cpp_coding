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

bool oper(char c)
{
	switch (c)
	{
	case '+':
	case '-':
	case '*':
	case '/':
		return true;
	}
	return false;
}


string preToInfix(string que)
{
	stack<string> st;
	for (int i = que.length() - 1; i >= 0; i--)
	{
		if (oper(que[i]))
		{
			string c1 = st.top();
			st.pop();
			string c2 = st.top();
			st.pop();

			string temp = '(' + c1 + que[i] + c2 + ')';
			st.push(temp);
		}
		else
		{
			st.push(string(1, que[i])); //    <-- important point
		}
	}
	return st.top();
}

int main()
{
	sublime();
	string pre_exp = "*-A/BC-/AKL";
	string temp = preToInfix(pre_exp);
	cout << temp;
	return 0;
}


