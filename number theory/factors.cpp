#include <bits/stdc++.h>
#define int long long
using namespace std;

void sublime()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}

vector<int> fact(int n){
	vector<int> ans;
	for(int i=1;i*i<=n;i++){
		if(!(n%i)){
			ans.push_back(i);
			if(i!=n/i){
				ans.push_back(n/i);
			}
		}
	}
	return ans;
}



int32_t main() {
	sublime();
	vector<int> ans;
	int n;
	cin>>n;
	ans=fact(n);
	sort(ans.begin(), ans.end());
	for(auto i:ans){
		cout<<i<<endl;
	}
}