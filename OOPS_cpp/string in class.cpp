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
	void putname(string n);  // focus on string operations , who strings are passed and
	string getname();  		 // and returned
private: //again private , we can change mutiple times , but this style is not preferd
	int wage;
public:
	void setwage(int n);
	int getwage();
};

void emp::putname(string n)
{
	name = n;
}

string emp::getname()
{
	return name;
}


void emp::setwage(int z)
{
	wage = z;
}

int emp::getwage()
{
	return wage;
}

int main()
{
	sublime();
	emp viv;
	string NAME;
	viv.putname("Vivek");
	viv.setwage(1000000);
	cout << viv.getname() << " " << viv.getwage() << endl;
	return 0;
}