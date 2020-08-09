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
void dfs(int);
vi v[100000];
int visited[100000];
int32_t main()
{
	sublime();
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
	}
	for (int i = 0; i < n; i++)
	{
		cout << i << " -> ";
		for (int j = 0; j < v[i].size(); j++) cout << v[i][j] << " ";
		cout << endl;
	}

	for (int i = 0; i < n; i++)
	{
		if (visited[i] == 0) dfs(i);
	}
	return 0;
}

void dfs(int start)
{
	cout << start << " ";
	visited[start] = -1;
	for (int i = 0; i < v[start].size(); i++)
	{
		int current = v[start][i];
		if (visited[current] == 0)	dfs(current);
	}
}

/*
5 5
0 2
2 1
2 4
4 1
1 3
*/