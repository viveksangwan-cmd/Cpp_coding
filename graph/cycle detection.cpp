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


bool bfs(vector<vector<int>> graph, vector<bool> &visited, int source)
{
	queue<int> q;
	q.push(source);
	while (!q.empty())
	{
		int current = q.front();
		if (visited[current] == true) return true;
		visited[current] = true;

		q.pop();
		for (int i = 0; i < graph[current].size(); i++) {
			int now = graph[current][i];
			if (visited[now] == false) {
				q.push(graph[current][i]);
			}
		}
	}
	return false;
}



int main()
{
	sublime();
	int n, e;
	cin >> n >> e;

	vector<vector<int>> graph(n);
	for (int i = 0; i < e; i++) {
		int a, b, w;
		cin >> a >> b >> w;
		graph[a].push_back(b);

	}

	vector<bool> visited(n, false);
	for (int i = 0; i < n; i++) {
		if (visited[i] == false)
		{
			bool t = bfs(graph , visited, i);
			if (t) {
				cout << "true";
				return 0;
			}
		}
	}
	cout << "false";
	return 0;
}

