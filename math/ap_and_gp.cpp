#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void ap_series();
void gp_series();
int main() 
{
	int n;
	cout<<"Enter your choice: \n1)A.P. \n2)G.P."<<endl;
	cin>>n;
	switch(n)
	{
		case 1:
			ap_series();
			break;
		case 2:
			gp_series();
			break;
	}
    return 0;
}
 
void ap_series()
{
	int a,d,n;
	cout<<"Enter the value of \"a\" and \"d\" :"<<endl;
	cin>>a>>d;
	cout<<"Enter the no of elements you want in series :"<<endl;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cout<<a+i*d<<" ";
	}
}
void gp_series()
{
	int a,r,n;
	cout<<"Enter the value of \"a\" and \"r\" :"<<endl;
	cin>>a>>r;
	cout<<"Enter the no of elements you want in series :"<<endl;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
	cout<<a*(pow(r,i))<<" ";	
	}	
}
