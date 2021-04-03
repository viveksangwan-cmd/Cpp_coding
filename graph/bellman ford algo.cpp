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

vector<int> bellman_ford(int V,int src,vector<vector<int>> edges){
	vector<int> distances(V+1,INT_MAX);
	distances[src] = 0;


	bool changes;

	// Relaxation Check
	for(int i=0;i<V-1;i++){
		changes = false;
		for(auto edge : edges){
			int u = edge[0];
			int v = edge[1];
			int wt = edge[2];

			if(distances[u]!=INT_MAX and distances[u] + wt < distances[v]){
				distances[v] = distances[u] + wt;
				changes = true;
			}
		}
		// If no changes means Shortest Path Configuration is recorded
		if(!changes){
			return distances;
		}
	}

// Checking for V'th time if there are changes means there is a negative cycle present
	for(auto edge : edges){
		int u = edge[0];
		int v = edge[1];
		int wt = edge[2];
		if(distances[u]!=INT_MAX and distances[u] + wt < distances[v]){
			cout<<"Negative Cycle detected ";			
			exit(0);
		}
	}
	return distances;

}


int32_t main() {
	sublime();

	int n,m;
	cin>>n>>m;


	int u,v,wt;
	vector<vector<int>> edges;
	for(int i=0;i<m;i++){
		cin>>u>>v>>wt;
		edges.push_back({u,v,wt});
	}

	vector<int> ans = bellman_ford(v,1,edges);
	for(int i=1;i<=n;i++){
		cout<<"Distance of node "<<i<<" is "<<ans[i]<<endl;
	}

	return 0;
}




// 3 3 
// 1 2 3
// 2 3 4
// 1 3 -10

// Distance of node 1 is 0
// Distance of node 2 is 3
// Distance of node 3 is -10


 // 3 3 
 // 1 2 3
 // 2 3 4
 // 3 1 -10
// Negative Cycle detected 