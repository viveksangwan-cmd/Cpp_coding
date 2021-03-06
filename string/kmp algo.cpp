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

void kMPString(string txt, string pattern)
{
	int n = txt.length();
	int m = pattern.length();
	int i = 1, len = 0, j = 0;
	vi kamparr(m, 0);
	while (i < m)
	{
		if (pattern[i] == pattern[len])
		{
			len++;
			kamparr[i] = len;
			i++;
		}
		else
		{
			if (len != 0)
			{
				len = kamparr[len - 1];
			}
			else
			{
				kamparr[i] = 0;
				i++;
			}
		}
	}

	cout << "KMP suffix array of pattern : " << endl;
	for (int i = 0; i < m; i++) cout << kamparr[i] << " ";
	cout << endl;

	i = 0;
	j = 0;
	while (i < n)
	{
		if (pattern[j] == txt[i])
		{
			i++;
			j++;
		}
		if (j == m) cout << "found match at : " << i - j << endl, j = kamparr[j - 1];
		else if (i < n  && (pattern[j] != txt[i]))
		{
			if (j != 0) j = kamparr[j - 1];
			else
			{
				i++;
			}
		}
	}
}

int32_t main()
{
	sublime();
	string txt = "ababcabcabababd" , pattern = "ababd";
	kMPString(txt, pattern);
	return 0;
}


