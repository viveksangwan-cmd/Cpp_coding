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

int prec(char c)
{
	if (c == '^') {return 3;}
	else if (c == '*' || c == '/') {return 2;}
	else if (c == '+' || c == '-') {return 1;}
	else {return -1;}
}

string intopost(string que)
{
	string ans = "";
	stack<char> st;
	st.push('N');
	for (int i = 0; i < que.length(); i++)
	{
		if ((que[i] >= 'a' && que[i] <= 'z') || (que[i] >= 'A' && que[i] <= 'Z'))
		{
			ans += que[i];
		}
		else if (que[i] == '(')
		{
			st.push('(');
		}
		else
		{
			if (que[i] == ')')
			{
				while (st.top() != 'N' && st.top() != '(' )
				{
					char current = st.top();
					ans += current;
					st.pop();
				}
				if (st.top() == '(')	st.pop();
			}
			else
			{
				while (st.top() != 'N' && prec(st.top()) >= prec(que[i]))
				{
					char current = st.top();
					ans += current;
					st.pop();
				}
				st.push(que[i]);
			}
		}
	}
	while (st.top() != 'N')
	{
		char current = st.top();
		ans += current;
		st.pop();
	}
	return ans;
}


int main()
{
	sublime();
	string exp1 = "a+b*(c^d-e)^(f+g*h)-i";
	cout << intopost(exp1) << endl;
	return 0;
}


