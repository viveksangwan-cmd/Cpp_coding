#include<bits/stdc++.h>
using namespace std;

	// Vivek Sangwan
	// Poornima University
	// 4th year


#define ff              first
#define ss              second
#define int             long long
#define pb              push_back
#define mp              make_pair
#define pii             pair<int,int>
#define vi              vector<int>
#define mii             map<int,int>
#define pqb             priority_queue<int>
#define pqs             priority_queue<int,vi,greater<int> >
#define setbits(x)      __builtin_popcountll(x)
#define zrobits(x)      __builtin_ctzll(x)
#define mod             1000000007
#define inf             1e18
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(dp,n,type)  type *dp=new type[n];
#define w(x)            int x; cin>>x; while(x--)
#define rep(i,s,n)		for(int i=s;i<n;i++)

void sublime()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}



int32_t main()
{
	sublime();
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	// cout<<n<<endl;
	int minEle;
	for(int i=0;i<n-1;i++){
		minEle = i;
		for(int j=i+1;j<n;j++){
			if(arr[j]<arr[minEle]){
				minEle=j;
			}
		}
		swap(arr[i],arr[minEle]);
	}
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
	return 0;
}