#include <bits/stdc++.h>
#define int long long
#define	mod	1000000007
#define endl '\n'
using namespace std;

void sublime()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}

void insertionSort(int *arr,int n){
	for(int i=1;i<n;i++){
		int currentElement = arr[i];
		int j = i-1;
		while(j>=0 && arr[j]>currentElement){
			arr[j+1]=arr[j];
			j--;
		}
		arr[j+1]=currentElement;
	}
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}	
}


void solve(){
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	insertionSort(arr,n);
}

int32_t main() {
	sublime();
	int t=1;
	// cin>>t;
	while(t--){
		solve();
	}
}
