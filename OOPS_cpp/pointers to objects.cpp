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

class student
{
	int id;
public:
	student(int id) {this->id = id;}
	int get_id() {return id;}
};

int main()
{
	sublime();
	student s[3] = {1, 2, 3};
	student *p;
	p = s;
	for (int i = 0; i < 3; i++)
	{
		cout << p->get_id() << " ";
		p++;
	}
	return 0;
}