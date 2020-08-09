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
int sub_tree_size[100001];

int dfs(int source)
{
	visited[source] = 1;
	int curr_size = 1;
	for (int i : v[source])
	{
		if (visited[i] == 0) curr_size += dfs(i);
	}
	sub_tree_size[source] = curr_size;
	return curr_size;
}


int32_t main()
{
	sublime();
	int n;
	cin >> n;

	rep(i, 0, n)
	{
		int a, b;
		cin >> a >> b;
		v[a].pb(b);
		v[b].pb(a);
	}

	int ans = dfs(1);

	rep(i, 1, n + 1)
	cout << i << " -> " << sub_tree_size[i] << endl;

	return 0;
}

/*
7
1 2
2 3
2 4
3 7
4 5
4 6
*/