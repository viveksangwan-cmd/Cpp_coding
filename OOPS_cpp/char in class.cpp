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
	char name[80]; // private
public:   //public
	void putname(char *n);  // focus on char operations , who strings are passed and
	void getname(char *n);  // and returned
private: //again private , we can change mutiple times , but this style is not preferd
	int wage;
public:
	void setwage(int n);
	int getwage();
};

void emp::putname(char *n)
{
	strcpy(name, n);
}

void emp::getname(char *n)
{
	strcpy(n, name);
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
	char NAME[80];
	viv.putname("Vivek");
	viv.setwage(1000000);
	viv.getname(NAME);
	cout << NAME << " " << viv.getwage() << endl;
	return 0;
}