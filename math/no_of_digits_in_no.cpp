#include<bits/stdc++.h>
using namespace std;

int count_no(int no)
{
	if (no==0) return 0;
	else return 1+count_no(no/10);
}

int main()
{
	int no;
	cout<<"Enter the no: ";
	cin>>no;
	int no2=no;
	int count;
	while(no>0)
	{
		count+=1;
		no/=10;
	}
	cout<<"No of digits are "<<count<<" "<<count_no(no2);
	
	return 0;
}

