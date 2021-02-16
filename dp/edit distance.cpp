#include<bits/stdc++.h>
using namespace std;

	// Vivek Sangwan
	// Poornima University
	// 4th year


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
#define mk(dp,n,type)  type *dp=new type[n];
#define w(x)            int x; cin>>x; while(x--)
#define rep(i,s,n)		for(int i=s;i<n;i++)

void sublime()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}

void solve()
{
	string a,b;
	cin>>a>>b;
	int al=a.length();
	int bl=b.length();
	int dp[al+1][bl+1];
	for(int i=0;i<=al;i++){
		for(int j=0;j<=bl;j++){
			if(i==0){
				dp[i][j]=j;
			}else if(j==0){
				dp[i][j]=i;
				}
			else if(a[i-1]==b[j-1]){
				dp[i][j]=dp[i-1][j-1];
			}else{
				dp[i][j]=1+min({
				dp[i-1][j] // remove
				,dp[i-1][j-1] // replace
				,dp[i][j-1] // insert
				});
			}
		}
	}
	for(int i=0;i<=al;i++){
		for(int j=0;j<=bl;j++){
			cout<<dp[i][j]<<" ";			
		}
		cout<<endl;
	}
}

int32_t main()
{
	sublime();
	int t=1;
	// cin>>t;
	while(t--){
		solve();
	}
	return 0;
}