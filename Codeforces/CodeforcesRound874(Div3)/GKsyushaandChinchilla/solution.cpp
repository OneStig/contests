#include <bits/stdc++.h>

using namespace std;

int dfs(int x, int par, vector<vector<int>>& adj, vector<array<int, 2>>& cuts) {
	vector<int> children;

	for (int& nb : adj[x]) {
		if (nb == par) {
			continue;
		}

		int cur = dfs(nb, x, adj, cuts);
		if (cur == -1) return -1;

		if (cur) {
			children.push_back(cur);
		}
		else {
			// make a cut here
			cuts.push_back({x, nb});
		}
	}

	if (children.size() == 0) {
		return 1;
	}

	if (children.size() >= 3) {
		return -1;
	}

	if (children.size() == 1) {
		return (children[0] + 1) % 3;
	}

	// 2 children

	if (children[0] == 1 && children[1] == 1) {
		return 0;
	}

	return -1;
}

int main() {
	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;

		unordered_map<int, unordered_map<int, int>> matx;
		vector<vector<int>> adj(n + 1);
		vector<array<int, 2>> cuts;

		for (int i = 1; i < n; i++) {
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
			matx[u][v] = i;
			matx[v][u] = i;
		}

		int ans = dfs(1, -1, adj, cuts);

		if (ans == 0) {
			cout << cuts.size() << '\n';

			if (cuts.size()) {
				for (auto& k : cuts) {
					cout << matx[k[0]][k[1]] << ' ';
				}
				cout << '\n';
			}
			else {
				cout << '\n';
			}
		}
		else {
			cout << -1 << '\n';
		}
	}
}
