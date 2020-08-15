#include<iostream>
#include<cstring>
#include<string>
using namespace std;
void sublime()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.TXT", "r", stdin);
	freopen("output.TXT", "w", stdout);
#endif
}


class thread2;
class thread1
{
	int screen;
public:   //public
	friend int status_of_screen(thread1 x, thread2 y); // friend function , have access to private and protected members of class
	thread1(int x) {screen = x;};
	void set_screen(int x) {screen = x;};
};

class thread2
{
	int screen;
public:   //public
	friend int status_of_screen(thread1 x, thread2 y); // friend function , have access to private and protected members of class
	thread2(int x) {screen = x;}
	void set_screen(int x) {screen = x;}
};

int status_of_screen(thread1 a, thread2 b)
{
	if (a.screen == 0 and b.screen == 0) return 1;
	else return 0;
}

int main()
{
	sublime();
	thread1 a(0);
	thread2 b(0);

	if (status_of_screen(a, b)) cout << "Can be used" << endl;
	else cout << "Currently in use";

	a.set_screen(1);

	if (status_of_screen(a, b)) cout << "Can be used" << endl;
	else cout << "Currently in use";

	return 0;
}