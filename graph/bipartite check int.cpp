/*   Vivek Sangwan
	Poornima University */

#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;

void sublime()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.TXT", "r", stdin);
	freopen("output.TXT", "w", stdout);
#endif
}

bool dfs(vector<vector<int>> g,int *visited,int child,int prt,int color){
	visited[child] = color;
	for(auto nbr : g[child]){
		if(visited[nbr]==0){
			bool subproblem = dfs(g,visited,nbr,child,3-color);
			if(!subproblem){
				return false;
			}
		}else if(nbr!=prt && color==visited[nbr]){
			return false;
		}
	}
	return true;
}


void dfs_helper(vector<vector<int>> g,int n){

	// 0->not visited , 1->visited color 1 , 2->visited color 2
	int visited[n] = {0};
	bool t = dfs(g,visited,0,-1,1);
	if(!t){
		cout<<"Not bipartite"<<endl;
		return;
	}
	for(int i=0;i<n;i++){
		if(!visited[i]){
			if(!dfs(g,visited,i,-1,1)){
				cout<<"Not bipartite"<<endl;
				return;
			}
		}
	}
	cout<<"bipartite"<<endl;
}


int32_t main() {
	sublime();
	int n,m;
	cin>>n>>m;
	vector<vector<int>> g(n);
	for(int i=0;i<m;i++){
		int a,b;
		cin>>a>>b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	dfs_helper(g,n);
}


	// 5 5
	// 0 1
	// 0 3
	// 1 2
	// 2 4
	// 4 3	
