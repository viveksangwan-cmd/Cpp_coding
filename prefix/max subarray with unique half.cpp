/*   Vivek Sangwan
	Poornima University */

#include<bits/stdc++.h>
using namespace std;

#define ff              first
#define ss              second
#define int             long long
#define pb              push_back
#define mp              make_pair
#define pii             pair<int,int>
#define vi              vector<int>
#define mii             map<int,int>
#define pqb             priority_queue<int>
#define pqs             priority_queue<int,vi,greater<int> >
#define setbits(x)      __builtin_popcountll(x)
#define zrobits(x)      __builtin_ctzll(x)
#define mod             1000000007
#define inf             1e18
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define w            int x; cin>>x; while(x--)
#define rep(i,a,b)	for(int i=a;i<b;i++)
mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());


void sublime()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.TXT", "r", stdin);
	freopen("output.TXT", "w", stdout);
#endif
}

int longest(vi z)
{
	int n = z.size();
	int forward[n], backward[n];
	rep(i, 0, n)
	{
		if (i == 0 || z[i] != z[i - 1]) forward[i] = 1;
		else forward[i] = forward[i - 1] + 1;
	}
	for (int i = n - 1; i >= 0; i--)
	{
		if (i == n - 1 || z[i] != z[i + 1]) backward[i] = 1;
		else backward[i] = backward[i + 1] + 1;
	}
	for (auto x : forward) cout << x << " " ;
	cout << endl;
	for (auto x : backward) cout << x << " ";
	cout << endl;
	rep(i, 0, n - 1)
	{
		if (z[i] != z[i + 1]) cout << i << " " << max(forward[i], backward[i + 1]) << " " << max(forward[i], backward[i + 1]) * 2 << endl;
	}
	return 0;
}


// https://www.geeksforgeeks.org/maximum-length-of-subarray-consisting-of-same-type-of-element-on-both-halves-of-sub-array/

int32_t main()
{
	sublime();
	vi z{ 1, 2, 3, 4, 4, 4, 6, 6, 6, 9 };
	cout << longest(z);
	return 0;
}
