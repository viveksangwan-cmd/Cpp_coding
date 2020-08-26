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

// 5 7
// 0 1
// 0 2
// 0 3
// 1 3
// 2 3
// 1 4
// 2 4

vector<vi> g(1001);
int routes = 0;

void countNodes(int start, int end)
{
	if (start == end) routes++;
	else
	{
		for (int i = 0; i < g[start].size(); i++)
			countNodes(g[start][i], end);
	}
}


int32_t main()
{
	sublime();
	int n, e;
	cin >> n >> e;
	int a, b;

	rep(i, 0, e)
	{
		cin >> a >> b;
		g[a].pb(b);
	}

	rep(i, 0, n)
	{
		cout << i << " -> ";
		rep(j, 0, g[i].size())
		{
			cout << g[i][j] << " ";
		}
		cout << endl;
	}
	// routes btw node 0 and node 3
	countNodes(0, 3);
	cout << routes << endl; //3
	return 0;
}
