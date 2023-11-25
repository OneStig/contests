#include <bits/stdc++.h>

using namespace std;

vector<int> a;
vector<int> deg;
vector<vector<int>> adj;
vector<bool> vis;

int dfs(int x) {
	vis[x] = 1;
	int mx = a[x];

	for (int i = 0; i < adj[x].size(); i++) {
		int cur = adj[x][i];
		if (!vis[cur]) {
			mx = max(mx, dfs(cur));
		}
	}

	return mx;
}

int main() {
	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;

		a.resize(n);
		deg.resize(n);
		adj.resize(n);
		vis.resize(n);

		long long ans = 0;

		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}

		for (int i = 1; i < n; i++) {
			int u, v;
			cin >> u >> v;
			u--;
			v--;
			deg[u]++;
			deg[v]++;

			adj[u].push_back(v);
			adj[v].push_back(u);
		}

		vector<int> leaves;

		bool hit = 0;
		for (int i = 0; i < n; i++) {
			if (deg[i] > 2) {
				ans += a[i];
				hit = 1;
				vis[i] = 1;
			}

			if (deg[i] == 1) {
				leaves.push_back(i);
			}
		}

		if (!hit) {
			cout << 0 << endl;
		}

		for (int i = 0; i < leaves.size(); i++) {
			long long mx = dfs(leaves[i]);
			ans += mx;
		}

		cout << ans << endl;
		cout << "------" << endl;
	}
}
