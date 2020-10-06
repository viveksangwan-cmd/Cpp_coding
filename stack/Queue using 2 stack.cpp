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

struct queueS
{
	stack<int> s1, s2;


	void enQueue(int x)
	{
		s1.push(x);
	}

	int sizeQueue() { return s1.size();}
	int deQueue()
	{
		if (s1.empty())
		{
			return -1;
		}
		while (!s1.empty())
		{
			s2.push(s1.top());
			s1.pop();
		}

		int ans = s2.top();
		s2.pop();

		while (!s2.empty())
		{
			s1.push(s2.top());
			s2.pop();
		}
		return ans;
	}
};

int main()
{
	sublime();

	queueS q;
	q.enQueue(5);
	q.enQueue(9);
	q.enQueue(1);

	cout << q.deQueue() << endl;
	cout << q.sizeQueue() << endl;
	cout << q.deQueue() << endl;
	cout << q.deQueue() << endl;
	cout << q.sizeQueue() << endl;
	cout << q.deQueue() << endl;
	q.enQueue(1);
	cout << q.sizeQueue() << endl;



	return 0;
}


