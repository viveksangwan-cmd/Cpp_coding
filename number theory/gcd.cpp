#include <bits/stdc++.h>
#define int long long
using namespace std;

void sublime()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}


int gcd(int a,int b){
	if(b==0){
		return a;
	}
	else return gcd(b,a%b);
}

int32_t main() {
	sublime();
	int a,b;
	cin>>a>>b;
	cout<<gcd(a,b)<<" "<<__gcd(a,b);
}