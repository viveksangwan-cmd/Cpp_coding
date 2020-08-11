/*   Vivek Sangwan
	Poornima University */

#include<bits/stdc++.h>
using namespace std;

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
#define mk(arr,n,type)  type *arr=new type[n];
#define w            int x; cin>>x; while(x--)
#define rep(i,a,b)	for(int i=a;i<b;i++)
mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());


void sublime()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.TXT", "r", stdin);
	freopen("output.TXT", "w", stdout);
#endif
}

bool inside(int row, int col)
{
	return row >= 0 && row <= 7 && col >= 0 && col <= 7;
}
vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {
	vector<vector<int>> ans;
	vector<vector<bool>> t(8, vector<bool>(8));
	for (auto queen : queens)
	{
		t[queen[0]][queen[1]] = true;
	}
	for (int d1 = -1; d1 <= 1; d1++)
	{
		for (int d2 = -1; d2 <= 1; d2++)
		{
			if (d1 == 0 && d2 == 0) continue;
			int row = king[0];
			int col = king[1];
			do
			{
				row += d1;
				col += d2;
			} while (inside(row, col) && !(t[row][col]));
			if (inside(row, col)) ans.push_back({row, col});
		}
	}
	return ans;
}

int32_t main()
{
	sublime();
	// leetcode
	vector<vi> queens{{0, 1}, {1, 0}, {4, 0}, {0, 4}, {3, 3}, {2, 4}}, ans;
	vi king = {0, 0};
	ans = queensAttacktheKing(queens, king);
	for (auto i : ans) cout << i[0] << " " << i[1] << endl;
	return 0;
}


//queens = [[0,1],[1,0],[4,0],[0,4],[3,3],[2,4]], king = [0,0]