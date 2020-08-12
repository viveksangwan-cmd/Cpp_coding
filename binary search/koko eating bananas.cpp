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
bool poosible(vi v, int n, int h)
{
	int count = 0;
	float x;
	for (int i = 0; i < v.size(); i++)
	{
		x = v[i] * 1.0 / n;
		count += ceil(x);
	}
	if (count <= h) return true;
	else return false;
}
int maxK(vi v, int h)
{
	int low = 1;
	int high = *max_element(v.begin(), v.end());
	while (high - low > 1)
	{
		int mid = (low + high) / 2;
		if (poosible(v, mid, h)) high = mid;
		else low = mid + 1;
	}
	if (poosible(v, low, h)) return low;
	return high;
}

int32_t main()
{
	sublime();
	// leetcode 875
	vi v{3, 6, 7, 11};
	int h = 8;
	cout << maxK(v, h);//4
	return 0;
}


