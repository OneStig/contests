#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 200;

int main() {
	int t;
	cin >> t;

	while (t--) {
		int n, m;
		cin >> n >> m;

		vector<int> deg(n + 1);
		unordered_map<int, vector<int>> adj;

		for (int i = 0; i < m; i++) {
			int u, v;
			cin >> u >> v;
			deg[u]++;
			deg[v]++;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}

		int leaves = 0;
		unordered_set<int> branches;

		for (int i = 1; i <= n; i++) {
			if (deg[i] == 1) {
				leaves++;
				branches.insert(adj[i][0]);
			}
		}

		int x = branches.size();
		int y = leaves / x;

		cout << x << ' ' << y << '\n';
	}
}
