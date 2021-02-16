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

void generate(string a, int n) {

	int i = 0; // every bit of no;
	while (n > 0) {
		(n & 1) ? cout << a[i] : cout << "";
		i++;
		n = n >> 1;
	}
	cout << endl;
}


void generateSubsets(string a) {
	int len = a.length();
	int size = (1 << len) - 1;   //  pow(2,n)-1
	for (int i = 1; i <= size; i++) {
		generate(a, i);
	}

}

int32_t main()
{
	sublime();
	string n;
	cin >> n;
	generateSubsets(n);
}

