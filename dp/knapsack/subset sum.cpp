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

bool t[101][101];

bool subsetSUM(vi arr, int Sum, int no)
{
	rep(i, 0, no + 1)
	rep(j, 0, Sum + 1)
	{
		if (j == 0) t[i][j] = true;
		else if (i == 0) t[i][j] = false;
	}
	for (int i = 1; i <= no; i++)
	{
		for (int j = 1; j <= Sum; j++)
		{
			if (arr[i - 1] <= j) t[i][j] = (t[i - 1][j - arr[i - 1]] || t[i - 1][j]);
			else t[i][j] = t[i - 1][j];
		}
	}
	rep(i, 0, no + 1)
	{
		rep(j, 0, Sum + 1) cout << t[i][j] << " ";
		cout << endl;
	}

	return t[no][Sum];
}

int32_t main()
{
	sublime();
	vi  arr{ 3, 34, 4, 12, 5, 2};
	cout << subsetSUM(arr, 9, 6); //1
	return 0;
}


