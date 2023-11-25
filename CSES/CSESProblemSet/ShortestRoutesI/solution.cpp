#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, m;
	cin >> n >> m;

	vector<vector<pair<int, int> > > adj(n);
	vector<int> ans(n);

	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		adj[a].push_back({b, c});
		adj[b].push_back({a, c});
	}


}
