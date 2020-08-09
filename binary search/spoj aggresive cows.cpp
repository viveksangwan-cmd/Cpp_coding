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

int cows_rest(std::vector<int> v, int mid , int  cows)
{
	int rested_cows = 1;
	int last_rested_cow = v[0];
	for (auto i = v.begin() + 1; i != v.end(); i++)
	{
//		cout << " cows rest :" << *i - last_rested_cow << endl;
		if ((*i - last_rested_cow) >= mid)
		{
			last_rested_cow = *i;
			rested_cows++;
//			cout << "rested_cows : " << rested_cows << endl;
		}
//		cout << " *i last_rested_cow " << *i << " " << last_rested_cow << endl;
	}
//	cout << "mid and rested_cows : " << mid << " " << rested_cows << endl;
	if (rested_cows >= cows) return true;
	else return false;
}

int32_t main()
{
	sublime();
	w
	{
		std::vector<int> v;
		int stands, cows, ele;
		cin >> stands >> cows;
		for (int i = 0; i < stands; i++) cin >> ele , v.push_back(ele);
		int lo = 0, hi = *max_element(v.begin(), v.end()) -*min_element(v.begin(), v.end());
		sort(v.begin(), v.end());
		while (hi - lo > 1)
		{
//			cout << lo << " " << hi << " " << cows << endl;
			int mid = (lo + hi) / 2;
			if (cows_rest(v, mid, cows) == false) hi = mid - 1;
			else lo = mid;
		}
		if (cows_rest(v, hi, cows) == true) cout << hi << endl;
		else if (cows_rest(v, lo, cows) == true) cout << lo << endl;
	}
	return 0;
}
