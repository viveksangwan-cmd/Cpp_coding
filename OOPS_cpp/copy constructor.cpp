#include <iostream>
#include <new>
#include <cstdlib>
using namespace std;

void sublime()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.TXT", "r", stdin);
	freopen("output.TXT", "w", stdout);
#endif
}


class array
{
	int *arr ;
	int size;
public:
	array(int);
	array( const array &a);
	void put_i(int, int);
	int get(int i);
	~array()
	{
		delete [] arr;
	}
};

array::array(int size)
{
	try
	{
		arr = new int[size];
	}
	catch (bad_alloc xarr)
	{
		cout << "Can't intialized array" << endl;
	}
	this->size = size;
}
array::array(const array &a) // copy constructor it will initialize new memory for the new array object
{
	try
	{
		arr = new int[a.size];
	}
	catch (bad_alloc xa)
	{
		cout << "Can't intialize array" << endl;
	}
	size = a.size;
	for (int i = 0; i < size; i++) arr[i] = a.arr[i];
}

void array::put_i(int i, int j)
{
	if (i >= 0 and i < size)
	{
		arr[i] = j;
	}
}

int array::get(int i)
{
	if (i >= 0 and i < size)
	{
		return arr[i];
	}
	return 0;
}
int main()
{
	sublime();
	array a(10);
	for (int i = 0; i < 10; i++) a.put_i(i, i);
	for (int i = 0; i < 10; i++) cout << a.get(i) << " ";
	cout << endl;
	array b(a); // can't use copy constructor using b=a;
	for (int i = 0; i < 10; i++) cout << b.get(i) << " ";
	return 0;
}