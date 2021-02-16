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

void primeFact(int n)
{
	for (int i = 2; i * i <= n; i++)
	{
		if (n % i == 0)
		{
			int count = 0;
			while (n % i == 0)
			{
				count++;
				n /= i;
			}
			cout << i << "^" << count << endl;
		}
	}
	if (n > 1) cout << n << "^" << 1 << endl;
}

int main()
{
	sublime();
	int n;
	cin >> n;
	primeFact(n);
	return 0;
}