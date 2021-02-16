/*   Vivek Sangwan
	Poornima University */

#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;

void sublime()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.TXT", "r", stdin);
	freopen("output.TXT", "w", stdout);
#endif
}

int N=1e6+1;
vector<int> prime(N,true);
vector<int> lpf(N);	

void lpfCal(){
	for(int i=0;i<=N;i++){
		lpf[i]=i;
	}
	lpf[0]=1;
	lpf[1]=1;

	int i=2;
	int j;
	while(i*i<=N){
		int j=2*i;
		if(prime[i]){
			while(j<=N){
				if(lpf[j]>i){
					lpf[j]=i;
				}
				prime[j]=false;
				j+=i;
			}
		}
		i+=1;
	}
}

void solve(){
	int n;
	cin>>n;
	cout<<n-lpf[n]<<endl;
}


int32_t main() {
	sublime();
	lpfCal();
	int t=1;
	cin>>t;
	while(t--){
		solve();
	}
}