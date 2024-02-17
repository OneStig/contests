#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
#include <bits/debug.h>
#endif

using namespace std;

#define ll long long

const ll MOD = 998244353;

int main() {
	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;

		vector<vector<int>> adj(n);

		ll total = 2;

		for (int i = 1; i < n; i++) {
			int u, v;
			cin >> u >> v;
			u--, v--;

			adj[u].push_back(v);
			adj[v].push_back(u);

			total *= 2;
			total %= MOD;
		}

		dfs(0, adj);
	}
}
