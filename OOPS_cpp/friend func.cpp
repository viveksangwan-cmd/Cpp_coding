#include<iostream>
#include<cstring>
#include<string>
using namespace std;
void sublime()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.TXT", "r", stdin);
	freopen("output.TXT", "w", stdout);
#endif
}

class emp
{
	string name; // private
public:   //public
	friend string name_of_emp(emp x); // friend function , have access to private and protected members of class
	emp(string n) {name = n;}
};

string name_of_emp(emp x) // input arfument as object name , object whose data to be access
{
	return x.name;
}

int main()
{
	sublime();
	emp viv("Vivek");
	cout << name_of_emp(viv) << endl;
	return 0;
}