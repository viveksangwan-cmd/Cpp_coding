#include<bits/stdc++.h>
using namespace std;
#define w int x;cin>>x;while(x--)

void sublime()
{
#ifndef ONLINE_JUDGE
	freopen("input.TXT", "r", stdin);
	freopen("output.TXT", "w", stdout);
#endif

}

int bin_power(int x, int p)
{
	int res = 1;
	while (p)
	{
		if (p % 2) res *= x , p--;
		x *= x , p /= 2;
	}
	return res;
}

int mob_power(int x, int p, int e)
{
	int res = 1;
	while (p)
	{
		if (p % 2) res = (res * x) % e , p--;
		x = (x * x) % e , p /= 2;
	}
	return res;
}

int main()
{
	sublime();
	int n, p, e;
	cin >> n >> p >> e;
	cout << bin_power(n, p);
	return 0;
}