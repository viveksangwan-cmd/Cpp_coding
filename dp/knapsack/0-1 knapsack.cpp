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
int knapsack(int wt[], int val[], int z, int n)
{
	if (n == 0 || z == 0) return 0;
	if (dp[z][n] != -1) return dp[z][n];
	if (wt[n - 1] <= z) return dp[z][n] = max(val[n - 1] + knapsack(wt, val, z - wt[n - 1], n - 1), knapsack(wt, val, z, n - 1));
	return dp[z][n] = knapsack(wt, val, z, n - 1);
}


int32_t main()
{
	sublime();
	int wt[4] = {1, 2, 4, 5}, val[4] = {1, 4, 5, 7};
	int z = 7;
	memset(dp, -1, sizeof(dp));
	cout << knapsack(wt, val, z, (int)4); //11
	return 0;
}
