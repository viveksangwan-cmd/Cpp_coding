/*   Vivek Sangwan
	Poornima University */

#include<bits/stdc++.h>
using namespace std;

#define ff              first
#define ss              second
//#define int             long long
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
int MHA(vi arr, int size)
{
	stack<pair<int, int>> s1, s2;
	vector<int> nsl, nsr;
	for (int i = 0; i < size; i++)
	{
		if (s1.empty()) nsl.pb(-1);
		else if (s1.top().first < arr[i]) nsl.pb(s1.top().second);
		else
		{
			while (!s1.empty() && s1.top().first >= arr[i])
			{
				s1.pop();
			}
			if (s1.empty()) nsl.pb(-1);
			else nsl.pb(s1.top().second);
		}
		s1.push({arr[i], i});
	}
	for (int i = size - 1; i >= 0; i--)
	{
		if (s2.empty()) nsr.pb(size);
		else if (s2.top().first < arr[i]) nsr.pb(s2.top().second);
		else
		{
			while (!s2.empty() && s2.top().first >= arr[i])
			{
				s2.pop();
			}
			if (s2.empty()) nsr.pb(size);
			else nsr.pb(s2.top().second);
		}
		s2.push({arr[i], i});
	}
	reverse(nsr.begin(), nsr.end());

	int max_current = -1;
	for (int i = 0; i < size; i++)
	{
		max_current = max(max_current, ((nsr[i] - nsl[i] - 1) ) * (arr[i]));
	}
	return max_current;
}

void maxrec(vector<vi> mat)
{
	int size = mat[0].size();
	vi arr(size, 0);
	int maxans = -1;
	for (int i = 0; i < mat.size(); i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (mat[i][j] == 1)arr[j] += 1;
			else arr[j] = 0;
		}
		maxans = max(maxans, MHA(arr, size));
	}
	cout << maxans << endl;
}


int32_t main()
{
	sublime();
	vector<vi> v{{0, 1, 1, 0}, {1, 1, 1, 1}, {1, 1, 1, 1}, {1, 1, 0, 0}};
	maxrec(v);
	return 0;
}

//[18,6,6,6,1,-1]