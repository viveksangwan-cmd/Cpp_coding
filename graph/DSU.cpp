#include <bits/stdc++.h>
// #define int long long
using namespace std;

void sublime()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}

class Graph {
	int V;
	list<pair<int, int>> l;
public:
	Graph(int v) {
		V = v;
	}

	void addEdge(int u, int v) {
		l.push_back(make_pair(u, v));
	}

	int findSet(int i, int prt[]) {
		if (prt[i] == -1) {
			return i;
		}
		return prt[i] = findSet(prt[i], prt);
	}

	void union_set(int x , int y, int prt[], int rank[]) {
		int s1 = findSet(x, prt);
		int s2 = findSet(y, prt);
		if (s1 != s2) {
			if (rank[s1] < rank[s2]) {
				prt[s1] = s2;
				rank[s2] += rank[s1];
			} else {
				prt[s2] = s1;
				rank[s1] += rank[s2];
			}
		}
	}

	bool contains_cycle() {
		int *parent = new int[V];
		int *rank = new int[V];
		for (int i = 0; i < V; i++) {
			parent[i] = -1;
			rank[i] = 1;
		}

		for (auto edge : l) {
			int i = edge.first;
			int j = edge.second;

			int s1 = findSet(i, parent);
			int s2 = findSet(j, parent);
			if (s1 != s2) {
				union_set(i, j, parent, rank);
			} else {
				cout << "Same parents of " << i << " and " << j << endl;
				return true;
			}
		}

		delete [] parent;
		delete [] rank;
		return false;
	}
};

int main() {
	sublime();
	Graph g(7);
	g.addEdge(0, 1);
	g.addEdge(1, 2);
	g.addEdge(2, 3);
	g.addEdge(0, 4);
	g.addEdge(5, 6);
	g.addEdge(2, 5);
	g.addEdge(2, 6);

	cout << g.contains_cycle() << endl;

}