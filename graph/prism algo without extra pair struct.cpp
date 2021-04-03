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

class Graph{
	vector<pair<int,int>> *g;
	int v;
public:
	Graph(int v){
		this->v = v;
		g = new vector<pair<int,int>>[v];
	}

	void addEdge(int u,int y,int wt){
		g[u].push_back({y,wt});
		g[y].push_back({u,wt});
	}

	int prism(){
		priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> Q;
		bool *visited = new bool[v]{0};
		Q.push({0,1});
		int ans = 0;
		while(!Q.empty()){
			auto top = Q.top();
			Q.pop();

			int current = top.second;
			int wgt = top.first;
			if(visited[current]) continue;
			// cout<<current<<" "<<wgt<<" "<<ans<<endl;

			ans += wgt;
			visited[current] = 1;
			for(auto connected : g[current]){
				if(!visited[connected.first]){
					Q.push({connected.second,connected.first});
					// cout<<"Q push "<<connected.second<<" "<<connected.first<<endl;
				}
			}
		}
		return ans;		 
	}
};


int32_t main() {
	sublime();
	int n,m;
	cin>>n>>m;
	Graph g(n+2);
	int u,y,wt;
	for(int i=0;i<m;i++){
		cin>>u>>y>>wt;
		g.addEdge(u,y,wt);
	}
	cout<<g.prism();
}