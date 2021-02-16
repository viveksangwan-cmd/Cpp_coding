#include <bits/stdc++.h>
using namespace std;


vector<string> dest{"Malaysia", "Australia", "Germany", "Dubai", "France"};


bool cmp(pair<int, int>& a,
         pair<int, int>& b)
{
	return a.second > b.second;
}
void sort(map<int, int>& M)
{
	vector<pair<int, int> > A;
	for (auto& it : M) {
		A.push_back(it);
	}
	sort(A.begin(), A.end(), cmp);

	int maxV = A[0].second;
	for (auto& it : A) {
		if (it.second == maxV)
		{
			cout << dest[it.first - 1] << endl;
		} else {
			break;
		}
	}
}

int main() {
	map<int, int> value;

	string a;
	cin >> a;
	while (a[0] != '-') {
		int n = stoi(a);
		value[n]++;
		cin >> a;
	}

	sort(value);

	return 0;
}