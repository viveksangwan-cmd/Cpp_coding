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
#define hypotenuse(a, b) sqrt(a*a+b*b)

void sublime()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.TXT", "r", stdin);
	freopen("output.TXT", "w", stdout);
#endif
}
int dp[101][101];

void printlcs(string a, string b, int as, int bs)
{
	string z = "";
	while (as > 0 and bs > 0)
	{
		if (a[as - 1] == b[bs - 1])
		{
			z.pb(a[as - 1] );
			as--;
			bs--;
		}
		else
		{
			if (dp[as - 1][bs] > dp[as][bs - 1])
			{
				as--;
			}
			else bs--;
		}
	}
	reverse(z.begin(), z.end());
	cout << z << endl;
}


void subseq(string a, string b, int as, int bs)
{
	for (int i = 1; i <= as; i++)
	{
		for (int j = 1; j <= bs; j++)
		{
			if (a[i - 1] == b[j - 1]) dp[i][j] = 1 + dp[i - 1][j - 1];
			else dp[i][j] = max(dp[i - 1][j] , dp[i][j - 1]);
		}
	}
	printlcs(a, b, as, bs);
}

int32_t main()
{
	sublime();
	string a = "abcdefgh";
	string b = "abqcioh";
	memset(dp, 0, sizeof(dp));
	subseq(a, b, 8, 7);
	return 0;
}


