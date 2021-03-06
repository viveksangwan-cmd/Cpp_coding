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

int LCS(string a, string b, int al, int bl)
{
	for (int i = 0; i <= al; i++)
	{
		for (int j = 0; j <= bl; j++)
		{
			if (i == 0 || j == 0) dp[i][j] = 0;
		}
	}
	for (int i = 1; i <= al; i++)
	{
		for (int j = 1; j <= bl; j++)
		{
			if (a[i - 1] == b[j - 1]) dp[i][j] = 1 + dp[i - 1][j - 1];
			else dp[i][j] = max(dp[i - 1][j] , dp[i][j - 1] );
		}
	}
	for (int i = 0; i <= al; i++)
	{
		for (int j = 0; j <= bl; j++)
		{
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}
	return dp[al][bl];

}



int32_t main()
{
	sublime();
	string a, b;
	a = "abcdefgh";
	b = "abqcioh";
	memset(dp, -1, sizeof(dp)); //memset -> -1 or 0 ;
	cout << LCS(a, b, 8, 7) << endl;//4
	return 0;
}


