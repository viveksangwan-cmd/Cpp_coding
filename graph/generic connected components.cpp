/*
		Vivek Sangwan
   	Poorinma University

*/

#include<bits/stdc++.h>
using namespace std;


void sublime()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}

template<typename T>
class Graph{
	unordered_map<T,list<T>> adjlist;
public:
	Graph(){

	}

	void addEdge(T u, T v,bool bidir){
		adjlist[u].push_back(v);
		if(bidir){
			adjlist[v].push_back(u);
		}
	}

	void printGraph(){
		for(auto current:adjlist){
			cout<<current.first<<" -> ";
			for(auto child:current.second){
				cout<<child<<" ";
			}
			cout<<endl;
		}
	}


	void dfsHelper(T src,map<T,bool> &visited){
		visited[src]=true;
		for(auto child:adjlist[src]){
			if(visited[child]!=true){
				dfsHelper(child,visited);
			}
		}
	}


	void DFS(T src){
		map<T,bool> visited;
		int component=1;
		dfsHelper(src,visited);

		for(auto i:adjlist){
			auto current = i.first;
			if(visited[current]!=true){
				dfsHelper(current,visited);
				component++;
			}
		}
		cout<<"Total components are "<<component <<endl;
	}

};



int32_t main()
{
	sublime();
	Graph<string> g;
	g.addEdge("Putin","Trump",true);
	g.addEdge("Putin","Pope",true);
	g.addEdge("Putin","Modi",true); 
	g.addEdge("Trump","Modi",true);
	g.addEdge("Modi","Yogi",true);
	g.addEdge("Prabhu","Modi",true);
	g.addEdge("Yogi","Prabhu",true);
	g.addEdge("A","B",true);
	g.addEdge("C","D",true);
	g.DFS("Modi");
	return 0;
}