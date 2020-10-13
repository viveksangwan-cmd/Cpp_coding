#include <bits/stdc++.h>
using namespace std;

void sublime()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.TXT", "r", stdin);
	freopen("output.TXT", "w", stdout);
#endif
}

class edge {
public:
	int src;
	int nbr;
	int wgt;
	edge(int src, int nbr, int wgt) {
		this->src = src;
		this->nbr = nbr;
		this->wgt = wgt;
	}
};

struct pairA {
public:
	int vrtx;
	int ivrtx;
	int wgt;
	pairA(int vrtx, int ivrtx, int wgt) {
		this->vrtx = vrtx;
		this->ivrtx = ivrtx;
		this->wgt = wgt;
	}
};

class mycompare
{
public:
	int operator()(const pairA &lhs, const pairA &rhs) {
		return lhs.wgt > rhs.wgt;
	}
};



void prismAlgo(vector<vector<edge*>> graph, vector<bool> visited) {
	priority_queue<pairA, vector<pairA>, mycompare> pq;
	pq.push(pairA(0, -1, 0));
	while (!pq.empty()) {
		auto curent_node = pq.top();
		pq.pop();
		if (visited[curent_node.vrtx] == true) {
			continue;
		}
		visited[curent_node.vrtx] = true;
		if (curent_node.ivrtx != -1) {
			cout << "[" << curent_node.vrtx << "-" << curent_node.ivrtx << "@" << curent_node.wgt << "]" << endl;
		}
		for (auto conn : graph[curent_node.vrtx]) {
			if (visited[conn->nbr] == false) {
				pq.push(pairA(conn->nbr, curent_node.vrtx, conn->wgt));
			}
		}
	}
}


int main() {
	sublime();
	int n, e;
	cin >> n >> e;

	vector<vector<edge*>> graph(n);
	for (int i = 0; i < e; i++) {
		int a, b, w;
		cin >> a >> b >> w;
		graph[a].push_back(new edge(a, b, w));
		graph[b].push_back(new edge(b, a, w));
	}

	vector<bool> visited(n, false);
	prismAlgo(graph, visited);
	return 0;
}