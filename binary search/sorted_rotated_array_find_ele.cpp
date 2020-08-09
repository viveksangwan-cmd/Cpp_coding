/*   Vivek Sangwan
	Poornima University */


#include<bits/stdc++.h>
using namespace std;
#define int             long long int
#define vi              vector<int>
#define w 				int x;cin>>x;while(x--)
#define endl '\n'
void sublime()
{
#ifndef ONLINE_JUDGE
	freopen("input.TXT", "r", stdin);
	freopen("output.TXT", "w", stdout);
#endif

}
int arr[] = {3, 4, 5, 6, 7, 1, 2};
int n = 7;


int binary_search(int arr[], int lo, int hi, int ele)
{
	while (hi - lo > 1)
	{
		int mid = (lo + hi) / 2;
		if (arr[mid] == ele) return mid;
		if (arr[mid] < ele) lo = mid + 1;
		else hi = mid - 1;
	}
	if (arr[lo] == ele) return lo;
	if (arr[hi] == ele) return hi;
	return 0;
}

int pivot_find(int arr[], int lo, int hi)
{
	if (hi < lo) return -1;
	if (hi == lo) return lo;
	int mid = (lo + hi) / 2;
	if (mid < hi && arr[mid] > arr[mid + 1]) return mid;
	if (mid > lo && arr[mid - 1] < arr[mid]) return mid - 1;
	if (arr[lo] > -arr[mid]) return pivot_find(arr, lo, mid - 1);
	return pivot_find(arr, mid + 1, hi);

}

int find_no(int arr[], int n, int ele)
{
	int pivot = pivot_find(arr, 0, n);
	if (pivot == -1) return binary_search(arr, 0, n, ele);
	if (arr[pivot] == ele) return pivot;
	if (arr[0] <= ele) return binary_search(arr, 0, pivot - 1, ele);
	return binary_search(arr, pivot + 1, n, ele);
}

int32_t main()
{
	sublime();
	cout << find_no(arr, n, 2);
	return 0;
}
