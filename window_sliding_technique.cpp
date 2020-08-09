/*   Vivek Sangwan
	Poornima University */

#include<bits/stdc++.h>
using namespace std;
int main()
{
	int arr[] = {1, 2, 3, 4, 5, 10, 43, 2, 6, 1, 32};
	int size = sizeof(arr) / sizeof(arr[0]);
	int k = 4;
	int sum;
	for (int i = 0; i < k; i++)
	{
		sum += arr[i];
	}
	cout << "First four : " << sum << endl;
	int window_sum = sum;
	for (int i = k; i < size; i++)
	{
		window_sum += arr[i] - arr[i - k];
		cout << "window " << window_sum << endl;
		sum = max(window_sum, sum);
	}
	cout << sum;
	return 0;
}



// shikar garg
