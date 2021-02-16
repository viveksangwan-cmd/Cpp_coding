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

void topological_sort(vector<vector<int>> graph, vector<bool> &visited, int source, stack<int> &st) {
	if (visited[source] == false) {
		visited[source] = true;
		for (auto i : graph[source]) {
			if (visited[i] == false)
				topological_sort(graph, visited, i, st);
		}
	}
	st.push(source);
}


int main() {
	sublime();
	int n, e;
	cin >> n >> e;

	vector<vector<int>> graph(n);
	for (int i = 0; i < e; i++) {
		int a, b, w;
		cin >> a >> b;
		graph[a].push_back(b);
	}

	vector<bool> visited(n, false);
	stack<int> st;
	for (int i = 0; i < n; i++) {
		if (visited[i] == false) {
			topological_sort(graph, visited, i, st);
		}
	}

	while (!st.empty()) {
		cout << st.top() << endl;
		st.pop();
	}

	return 0;
}