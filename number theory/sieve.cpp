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

int N=1e5;
vector<bool> isprime(N+1,true);
void prime(int n){
	isprime[0]=false;
	isprime[1]=false;
	for(int i=2;i*i<=n;i++){
		if(isprime[i]){
			for(int j=i*i;j<=n;j+=i){
				isprime[i]=false;
			}
		}
	}
}


int32_t main() {
	sublime();
	int a;
	cin>>a;
	prime(a);
	cout<<((isprime[a]==true)?"True":"False");
}