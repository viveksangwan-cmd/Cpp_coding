/*   Vivek Sangwan
	Poornima University */

#include<bits/stdc++.h>
using namespace std;
#define int             long long int
#define ff              first
#define ss              second
#define pb              push_back
#define mp              make_pair
#define pii             pair<int,int>
#define vi              vector<int>
#define mii             map<int,int>
#define pqb             priority_queue<int>
#define pqs             priority_queue<int,vi,greater<int> >
#define mod             1000000007
#define inf             1e18
#define w 				int x;cin>>x;while(x--)
#define rep(i,a,b)		for(int i=a;i<b;i++)
#define endl '\n'
void sublime()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.TXT", "r", stdin);
	freopen("output.TXT", "w", stdout);
#endif
}
bool dfs(int, int);
int mind = inf, ans = 0;
vi v[100001];
int c[100001];
int visited[100001];
int32_t main()
{
	sublime();
	int t;
	cin >> t;
	int x = 0;
	while (x++ < t)
	{
		int n, m, a, b;
		cin >> n >> m;
		bool t = true;
		for (int i = 1; i <= n; i++) v[i].clear(), visited[i] = 0;
		for (int i = 1; i <= m; i++)
		{
			cin >> a >> b;
			v[a].pb(b);
			v[b].pb(a);
		}
		for (int i = 1; i <= n; i++)
		{
			if (visited[i] == 0)
			{
				bool res = dfs(i, 0);
				if (res == false)
				{
					t = false ;
					break;
				}
			}
		}
		cout << "Scenario #" << x << ":" << endl;
		if (t)
		{
			cout << "No suspicious bugs found!" << endl;
		}
		else cout << "Suspicious bugs found!" << endl;
	}
	return 0;
}

bool dfs(int start, int color)
{
	c[start] = color;
	visited[start] = 1;
	for (auto x : v[start])
	{
		if (visited[x] == 0)
		{	bool res = dfs(x, color ^ 1);
			if (res == false) return false;
		}
		else if (c[start] == c[x]) return false;


	}
	return true;
}
