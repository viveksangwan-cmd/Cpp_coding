#include<bits/stdc++.h>
using namespace std;
#define w(x)            int x; cin>>x; while(x--)

void sublime()
{
#ifndef ONLINE_JUDGE
	freopen("input.TXT", "r", stdin);
	freopen("output.TXT", "w", stdout);
#endif

}
bool isPrime(int n)
{
	if (n <= 1) return false;
	for (int i = 2; (i * i) <= n; i++)
	{
		if (n % i == 0) return false;
	}
	return true;
}

int main()
{

	sublime();
	int m;
	cout << "Hello" << endl;
	w(x)
	{
		cin >> m;
		isPrime(x) ? cout << "Prime" : cout << "Not Prime";

	}
	return 0;
}