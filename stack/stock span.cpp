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

void spanstack(vi v)
{
	stack<pair<int, int>> s;
	vi ans;
	for (int i = 0; i < v.size(); i++)
	{
		if (s.empty()) ans.pb(i + 1);
		else if (s.top().first > v[i]) ans.pb(i - s.top().second);
		else
		{
			while (!s.empty() && s.top().first <= v[i])
			{
				s.pop();
			}
			if (s.empty()) ans.pb(i + 1);
			else ans.pb(i - s.top().second );
		}
		s.push({v[i], i});
	}
	for (auto i : ans) cout << i << " ";
	cout << endl;
}


int32_t main()
{
	sublime();
	vi vi1{100, 80, 60, 70, 60, 75, 85}, z;
	spanstack(vi1);
	return 0;
}

//[18,6,6,6,1,-1]