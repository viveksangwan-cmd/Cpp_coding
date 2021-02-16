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


// x^n
int binaryExpo(int x,int n){
	if(n==0){
		return 1;
	}else if(n%2==0){
		return binaryExpo(x*x,n/2);
	}else{
		return x*binaryExpo(x*x,(n-1)/2);
	}
}
int modularExponentiation(int x,int n,int M)
{
    if(n==0)
        return 1;
    else if(n%2 == 0)        //n is even
        return modularExponentiation((x*x)%M,n/2,M);
    else                             //n is odd
        return (x*modularExponentiation((x*x)%M,(n-1)/2,M))%M;

}
int32_t main() {
	sublime();
	int a,b;
	cin>>a>>b;
	cout<<binaryExpo(a,b);
}