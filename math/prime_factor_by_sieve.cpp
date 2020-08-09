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

int arr[100001];

void sieve()
{
	int n = 100001;
	for (int i = 0; i <= n; i++) arr[i] = -1;
	arr[0] = arr[1] = 0;
	for (int i = 2; i <= n; i++)
	{
		if (arr[i] == -1)
		{
			for (int j = i; j <= n; j += i)
			{
				if (arr[j] == -1) arr[j] = i;
			}
		}
	}
}

int main()
{
	sublime();
	sieve();
	int n;
	cin >> n;
	while (n)
	{
		cout << arr[n] << endl;
		n /= arr[n];
	}
	return 0;
}