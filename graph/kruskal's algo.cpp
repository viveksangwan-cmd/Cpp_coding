/*   Vivek Sangwan
	Poornima University */

#include<bits/stdc++.h>
using namespace std;
#define int long long

void sublime()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.TXT", "r", stdin);
	freopen("output.TXT", "w", stdout);
#endif
}

class Dsu{
	int *prt;
	int *rank;
public:
	Dsu(int V){
		prt = new int[V+1];
		rank = new int[V+1];
		for(int i=0;i<=V;i++){
			prt[i] = -1;
			rank[i] = 1;
		}
	}

	int find(int u){
		return (prt[u]==-1)? u : prt[u] = find(prt[u]);
	}

	void addEdge(int u,int v){
		int su = find(u);
		int sv = find(v);
		if(su!=sv){
			 if(rank[su]<rank[sv]){
			 	prt[su] = sv;
			 	rank[sv] += rank[su];  
			 }else{
			 	prt[sv] = su;
			 	rank[su] += rank[sv];
			 }
		}
	}
};

class Graph{
	int V;
	vector<vector<int>> edgelist;
public:
	Graph(int V){
		this->V = V;
	}

	void addEdge(int x,int y,int wt){
		edgelist.push_back({wt,x,y});
	}

	int kruskals(){
		int ans = 0;
		Dsu s(V);

		sort(edgelist.begin(),edgelist.end());

		for(auto i:edgelist){
			int u = i[1];
			int y = i[2];
			int wt = i[0];

			if(s.find(u)!=s.find(y)){
				ans+=wt;
				s.addEdge(u,y);
			}
		}
		return ans;
	}
};


int32_t main() {
	sublime();
	int n,m;
	cin>>n>>m;
	Graph g(n);
	int u,y,wt;
	for(int i=0;i<m;i++){
		cin>>u>>y>>wt;
		g.addEdge(u,y,wt);
	}
	cout<<g.kruskals();
}


// 4 6
// 1 2 1
// 1 3 2
// 2 4 3
// 2 3 3
// 1 4 2
// 2 3 2

// 5
