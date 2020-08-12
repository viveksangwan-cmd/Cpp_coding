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

int dp[101][101];
int SubsetSumwithMinimumDiff(vi v, int total, int n)
{
	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j <= total / 2; j++)
			if (j == 0) dp[i][j] = 1;
			else if (i == 0) dp[i][j] = 0;
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= total / 2; j++)
		{
			if (v[i - 1] <= total) dp[i][j] = dp[i - 1][j - v[i - 1]] || dp[i - 1][j];
			else dp[i][j] = dp[i - 1][j];
		}
	}
	for (int i = total / 2; i >= 1; i--)
	{
		if (dp[n][i] == 1) return total - 2 * i;
	}
	return 0;
}



int32_t main()
{
	sublime();
	vi  arr{ 3, 34, 8, 12, 5, 2};
	int total = 0, z;
	for (auto i : arr) total += i;
	cout << SubsetSumwithMinimumDiff(arr, total, 6); //1
	return 0;
}


