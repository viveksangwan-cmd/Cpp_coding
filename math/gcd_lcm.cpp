#include<bits/stdc++.h>
using namespace std;

int gcd(int a,int b)
{
	if(a==0) return b;
	cout<<(b%a)<<" "<<a<<endl;
	return gcd(b%a,a);
}

void lcm(int a,int b)
{
	int ans;
	int gcd_ans=gcd(a,b);
	ans=(a*b)/gcd_ans;
	cout<<"GCD = "<<gcd_ans<<endl;
	cout<<"LCM = "<<ans;
}

int main()
{
	int a,b;
	cout<<"Enter 2 numbers : "<<endl;
	cin>>a>>b;
	lcm(a,b);
	return 0;
}
