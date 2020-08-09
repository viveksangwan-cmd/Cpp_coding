#include<bits/stdc++.h>
using namespace std;

int gcd(int a , int b)
{
	if (a==0) return b;
	return gcd(b%a,a);
}

int main()
{
	int arr[]={2, 7, 3, 9, 4},ans;
	ans=arr[0];
	int size=sizeof(arr)/sizeof(arr[0]);
	for(int i=0;i<size;i++)
	{
		ans=(arr[i]*ans)/gcd(arr[i],ans);
	}
	cout<<"LCM = "<<ans;
	return 0;
}
