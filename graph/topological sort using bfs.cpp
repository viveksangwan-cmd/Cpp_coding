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
	list<int> *l;
	int v;
public:
	Graph(int v) {
		this->v = v;
		l = new list<int>[v];
	}

	void addEdge(int v, int u) {
		l[v].push_back(u);
	}

	void topologicalSort() {
		queue<int> q;
		int *inorder = new int[v];
		for (int i = 0; i < v; i++) {
			inorder[i] = 0;
		}

		for (int i = 0; i < v; i++) {
			for (auto j : l[i]) {
				inorder[j]++;
			}
		}

		for (int i = 0; i < v; i++) {
			if (inorder[i] == 0) {
				q.push(i);
			}
		}

		while (!q.empty()) {
			int current = q.front();
			cout << current << " ";
			q.pop();
			for (auto j : l[current]) {
				inorder[j]--;
				if (inorder[j] == 0) {
					q.push(j);
				}
			}
		}

	}

};

int main() {
	sublime();
	int n; cin >> n;
	Graph g(n);
	int e; cin >> e;
	for (int i = 0; i < e; i++) {
		int x, y; cin >> x >> y;
		g.addEdge(x, y);
	}

	g.topologicalSort();
}

// 6 7
// 0 2
// 1 4
// 1 2
// 4 5
// 2 5
// 2 3
// 3 5

// 0 1 4 2 3 5
