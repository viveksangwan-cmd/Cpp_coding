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

int kthSmallest(vi q, int k)
{
	priority_queue<int> z;
	for (int i = 0; i < q.size(); i++)
	{
		z.push(q[i]);
		if (z.size() > k) z.pop();
	}

	return z.top();
}

int32_t main()
{
	sublime();
	vi v = {4, 3, 2, 7, 8, 2, 3, 1}, ans{7, 10, 4, 3, 20, 15};
	cout << kthSmallest(v, 3);
	return 0;
}

//[18,6,6,6,1,-1]