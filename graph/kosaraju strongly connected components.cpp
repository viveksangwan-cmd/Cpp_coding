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

void dfs(int i,vector<vector<int>> graph,bool *visited,vector<int> &stk){
	visited[i]=true;
	for(auto nbr:graph[i]){
		if(!visited[nbr]){
			dfs(nbr,graph,visited,stk);
		}
	}
	stk.push_back(i);
}


void dfs2(int i,vector<vector<int>> graph,bool *visited){
	visited[i]=true;
	cout<<i<<" ";
	for(auto child:graph[i]){
		if(!visited[child]){
			dfs2(child,graph,visited);
		}
	}
}

void solve(int n,int m,vector<vector<int>> graph,vector<vector<int>> rev_graph){
	bool visited[n];
	memset(visited,0,n);
	vector<int> stk;

	// step 1) dfs -> ordering of nodes
	for(int i=0;i<n;i++){
		if(!visited[i]){
			dfs(i,graph,visited,stk);
		}
	}


	// step 2) rev of graph -> rev_graph

	// step 3) Do dfs using ordering to rev_graph
	memset(visited,0,n);
	char comment = 'A';
	for(int i=0;i<n;i++){
		if(!visited[i]){
			cout<<comment<<" -> ";
			dfs2(i,rev_graph,visited);
			cout<<endl;
			comment++;
		}
	}

}


int32_t main() {
	sublime();
	int n;
	cin>>n;

	 vector<vector<int>> graph(n),rev_graph(n);
	 int m;
	 cin>>m;
	 for(int i=0;i<m;i++){
	 	int a,b;
	 	cin>>a>>b;
	 	graph[a].push_back(b);
	 	rev_graph[b].push_back(a);
	 }
	 solve(n,m,graph,rev_graph);
}


	// 5 5
	// 0 1
	// 0 3
	// 1 2
	// 2 4
	// 4 3	



// A -> 0 1 2 
// B -> 3 6 5 
// C -> 4 
