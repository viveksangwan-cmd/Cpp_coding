#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

void sublime()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.TXT", "r", stdin);
	freopen("output.TXT", "w", stdout);
#endif
}

int powerMod(int a,int b,int c){
	int res=1;
	while(b){
		if(b&1){
			res=(res*a)%c;
		}
		a=(a*a)%c;
		b>>=1;
	}
	return res;
}

void solve(){
	int a,b;
	cin>>a>>b;
	cout<<"a^-1 of "<<a<<" under modulo "<<b<<" is -> "<<powerMod(a,b-2,b)<<endl;
} 


int32_t main()
{
	sublime();
	int t;
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}

