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
#define N 101
int arr[N][N], I[N][N];

void mul(int arr[][N], int b[][N], int dim)
{
	int res[dim + 1][dim + 1];
	rep(i, 0, dim)
	{
		rep(j, 0, dim)
		{
			res[i][j] = 0;
			rep(k, 0, dim) res[i][j] += arr[i][k] * b[k][j];
		}
	}
	rep(i, 0, dim) rep(j, 0, dim) arr[i][j] = res[i][j];
}

void power(int arr[][N], int dim, int n)
{
	rep(i, 0, dim) rep(j, 0, dim)
	{
		if (i == j) I[i][j] = 1;
		else I[i][j] = 0;
	}
	while (n)
	{
		if (n % 2) mul(I, arr, dim), n--;
		else mul(arr, arr, dim), n /= 2;
	}
	rep(i, 0, dim) rep(j, 0, dim) arr[i][j] = I[i][j];


}

void printmax(int a[][N], int n)
{
	rep(i, 0, n)
	{
		rep(j, 0, n) cout << arr[i][j] << " ";
		cout << endl;
	}
}

int32_t main()
{
	sublime();
	w
	{
		int dim, n;
		cin >> dim >> n;
		rep(i, 0, dim)rep(j, 0, dim) cin >> arr[i][j];
		power(arr, dim, n);
		printmax(arr, dim);
	}
	return 0;
}

