#include <bits/stdc++.h>
#define int long long
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

bool dfs(vector<bool> &visited,vector<bool> dfsCheck,vector<vector<int>> G,int src){
	if(visited[src]){
		return false;
	}
	visited[src]=true;
	dfsCheck[src]=true;
	for(auto dependency : G[src]){
		if(dfsCheck[dependency] || dfs(visited,dfsCheck,G,dependency)){
			return true;
		}
	}
	return false;
}


bool canFinish(vector<pair<int,int>> prereq,int numTasks){
	vector<vector<int>> G(numTasks);
	for(auto req : prereq){
		G[req.second].push_back(req.first);
	}

	vector<bool> visited(numTasks,false);
	vector<bool> dfsCheck(numTasks,false);	
	for(int i=0;i<numTasks;i++){
		if(!visited[i]){
			if((dfs(visited,dfsCheck,G,i))){
				return false;
			}
		}
	}
	return true;
}	

int32_t main() {
	sublime();
	int numTasks = 4;
	vector<pair<int,int>> prereq;
	prereq.push_back(make_pair(1,0));
	prereq.push_back(make_pair(2,1));
	prereq.push_back(make_pair(3,2));
	if(canFinish(prereq,numTasks)){
		cout<<"YES"<<endl;
	}else{
		cout<<"NO"<<endl;
	}
}


// https://www.geeksforgeeks.org/find-whether-it-is-possible-to-finish-all-tasks-or-not-from-given-dependencies/