#include <bits/stdc++.h>
using namespace std;

void sublime()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.TXT", "r", stdin);
	freopen("output.TXT", "w", stdout);
#endif
}

int countSwaps = 0;
void bubbleSort(int *arr, int n) {

	bool t;
	for (int i = 0; i < n - 1; i++) {
		t = true;
		for (int j = 0; j < n - i - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				t = false;
				int temp = arr[j + 1];
				arr[j + 1] = arr[j];
				arr[j] = temp;
				countSwaps++;
			}
		}
		if (t) return;
	}
}


int main() {
	sublime();
	int arr[] = {5, 1, 3, 6, 7};
	int n = sizeof(arr) / sizeof(arr[0]);

	bubbleSort(arr, n);

	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	cout << endl << countSwaps << endl;

}