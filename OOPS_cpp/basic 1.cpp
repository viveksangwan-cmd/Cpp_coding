#include<iostream>
using namespace std;
void sublime()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.TXT", "r", stdin);
	freopen("output.TXT", "w", stdout);
#endif
}

class math_all
{
	int a, b;
public:
	math_all(int i, int j) {a = i, b = j;} // constructor
	void print_a_b(); // public function
};

void math_all::print_a_b() // public function declaration
{
	cout << a << " " << b << endl;
	return;
}

int main()
{
	sublime();
	math_all obj(1, 2);
	obj.print_a_b();// 1 2
}