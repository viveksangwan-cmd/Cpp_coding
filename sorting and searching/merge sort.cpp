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

void merge(int *arr,int start,int mid,int end){
	int temp[end-start+1];
	int i = start;
	int j = mid+1;
	int k=0;
	while(i<=mid && j<=end){
		if(arr[i]<=arr[j]){
			temp[k]=arr[i];
			k++;
			i++;
		}else{
			temp[k]=arr[j];
			k++;
			j++;
		}
	}
	while(i<=mid){
		temp[k]=arr[i];
		k++;
		i++;
	}
	while(j<=end){
		temp[k]=arr[j];
		j++;
		k++;
	}

	for(int i=start ;i<=end;i++){
		arr[i]=temp[i-start];
	}
}

void mergeSort(int *arr,int start,int end){
	if(start<end){
		int mid  = (start+end) / 2;
		mergeSort(arr,start,mid);
		mergeSort(arr,mid+1,end);
		merge(arr,start,mid,end);
	}
}

void solve(){
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	mergeSort(arr,0,n-1);
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
}

int32_t main() {
	sublime();
	int t=1;
	// cin>>t;
	while(t--){
		solve();
	}
}
