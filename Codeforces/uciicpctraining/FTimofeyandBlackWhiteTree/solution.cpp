#include <bits/stdc++.h>

using namespace std;

int mx;

void dfs(int x, vector<vector<int>>& adj, vector<int>& dist, vector<bool>& vis) {
	if (dist[x] > mx) {
		return;
	}

	for (auto nb : adj[x]) {

	}
}

int main() {
	int t;
	cin >> t;

	while (t--) {
		int n, start;
		cin >> n >> start;
		start--;
		mx = n;

		vector<vector<int>> adj(n);
		vector<int> dist(n, INT_MAX);
		dist[start] = 0;
		vector<int> c(n - 1);

		for (int& x : c) {
			cin >> x;
		}

		for (int i = 1; i < n; i++) {
			int u, v;
			cin >> u >> v;

			adj[u].push_back(v);
			adj[v].push_back(u);
		}

		vector<bool> vis(n);
		dfs(start, adj, dist, vis);

		vector<int> ans;

		for (int i = 0; i < n - 1; i++) {
			mx = min(mx, dist[c[i]]);
			ans.push_back(mx);
		}
	}
}
