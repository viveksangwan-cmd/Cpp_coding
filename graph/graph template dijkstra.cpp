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

template<typename T>
class Graph {
	unordered_map < T, list<pair<T, int>>> m;
public:
	void addEdge(T source, T dest, int wgt, bool bidir = true) {
		m[source].push_back(make_pair(dest, wgt));
		if (bidir) {
			m[dest].push_back(make_pair(source, wgt));
		}
	}

	void printGraph() {
		for (auto i : m) {
			cout << i.first << "->";
			for (auto value : i.second) {
				cout << "(" << value.first << "," << value.second << ")";
			}
			cout << endl;
		}
	}

	void dijkstraSSSP(T source) {
		unordered_map<T, int> dist;

		for (auto i : m) {
			dist[i.first] = INT_MAX;
		}
		dist[source] = 0;

		set<pair<int, T>> s;
		s.insert(make_pair(0, source));

		while (!s.empty()) {
			auto current = *(s.begin());
			T current_source = current.second;
			int current_dist = current.first;
			s.erase(s.begin());

			for (auto nbr : m[current_source]) {
				if (current_dist + nbr.second < dist[nbr.first]) {

					T deleteset = nbr.first;
					auto findset = s.find(make_pair(dist[deleteset], deleteset));
					if (findset != s.end()) {
						s.erase(findset);
					}
					dist[deleteset] = current_dist + nbr.second;
					s.insert(make_pair(dist[deleteset], deleteset));
				}
			}
		}

		for (auto i : dist) {
			cout << i.first << " is located at a distance of " << i.second << endl;
		}

	}

};

int main()
{
	sublime();
	Graph<string> g;
	g.addEdge("Amritser", "Delhi", 1);
	g.addEdge("Amritser", "Jaipur", 4);
	g.addEdge("Jaipur", "Delhi", 2);
	g.addEdge("Jaipur", "Mumbai", 8);
	g.addEdge("Bhopal", "Agra", 2);
	g.addEdge("Mumbai", "Bhopal", 3);
	g.addEdge("Agra", "Delhi", 1);
//	g.printGraph();
	g.dijkstraSSSP("Amritser");
	return 0;
}

