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

int visited[100001];
vi v[100001];
int MaxD , max_node ;

void dfs(int source, int dis)
{
	visited[source] = 1;
	if (dis > MaxD) MaxD = dis, max_node = source;
	cout << source << " " << dis << " " << MaxD << endl;
	for (int i : v[source])
	{
		if (visited[i] == 0) dfs(i, dis + 1);
	}
}


int32_t main()
{
	sublime();
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) visited[i] = 0, v[i].clear();
	for (int i = 1; i <= n - 1; i++)
	{
		int a, b;
		cin >> a >> b;
		v[a].pb(b);
		v[b].pb(a);
	}
	MaxD = -1;
	dfs(1, 0);

	for (int i = 1; i <= n; i++) visited[i] = 0;

	MaxD = -1;
	dfs(max_node, 0);

	cout << MaxD << endl;
	return 0;
}

/*
1
6
1 2
1 3
1 4
2 5
2 6
*/