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

int t[101][101];
int countSubsetSum(vi v, int sum, int n)
{
	for (int i = 0; i < n + 1; i++)
	{
		for (int j = 0; j < sum + 1; j++)
		{
			if (j == 0 ) t[i][j] = 1;
			else if (i == 0) t[i][j] = 0;
		}
	}
	for (int i = 1; i < n + 1; i++)
	{
		for (int j = 1; j < sum + 1; j++)
		{
			if (v[i - 1] <= j) t[i][j] = t[i - 1][j] + t[i - 1][j - v[i - 1]];
			else t[i][j] = t[i - 1][j];
		}
	}
	for (int i = 0; i < n + 1; i++)
	{
		for (int j = 0; j < sum + 1; j++)
		{
			cout << t[i][j] << " ";
		}
		cout << endl;
	}
	return t[n][sum];
}


int32_t main()
{
	sublime();
	vi  arr{ 0, 1, 2};
	cout << countSubsetSum(arr, 0, 3);
	return 0;
}


