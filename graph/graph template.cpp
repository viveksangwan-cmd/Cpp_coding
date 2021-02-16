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

};

int32_t main()
{
	sublime();
	Graph<string> g;
	g.addEdge("Putin","Trump",false);
	g.addEdge("Putin","Pope",false);
	g.addEdge("Putin","Modi",false);
	g.addEdge("Trump","Modi",true);
	g.addEdge("Modi","Yogi",true);
	g.addEdge("Prabhu","Modi",false);
	g.addEdge("Yogi","Prabhu",false);
	g.printGraph();
	return 0;
}