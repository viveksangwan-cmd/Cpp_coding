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


void bfs(vector<vector<int>> graph, vector<int> visited, int source)
{
	queue<pair<int, string>> q;
	q.push({source, "@" + to_string(source)});
	visited[source] = -1;
	while (!q.empty())
	{
		int current = q.front().first;
		string path = q.front().second;
		q.pop();
		cout << current << path << endl;
		for (int i = 0; i < graph[current].size(); i++) {
			int now = graph[current][i];
			if (visited[now] != -1) {
				q.push({graph[current][i], path + to_string(graph[current][i])});
				visited[now] = -1;
			}
		}
	}
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
		graph[b].push_back(a);

	}


	int source;
	cin >> source;
	vector<int> visited(n, 0);
	bfs(graph , visited, source);
	return 0;
}

