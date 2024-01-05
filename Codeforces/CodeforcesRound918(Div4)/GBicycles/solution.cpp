#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main() {
	int t;
	cin >> t;

	while (t--) {
		int n, m;
		cin >> n >> m;

		vector<array<ll, 2>> adj[1000];

		for (int i = 0; i < m; i++) {
			int u, v, w;
			cin >> u >> v >> w;
			u--;
			v--;

			adj[u].push_back({v, w});
			adj[v].push_back({u, w});
		}

		vector<ll> slow(n);

		for (int i = 0; i < n; i++) {
			cin >> slow[i];
		}

		vector<vector<bool>> vis(n, vector<bool>(1001, 0));
		vector<vector<ll>> cost(n, vector<ll>(1001, LLONG_MAX));

		priority_queue<array<ll, 3>> pq;

		cost[0][slow[0]] = 0;
		pq.push({0, 0, slow[0]});

		while (!pq.empty()) {
			ll cur = pq.top()[1], speed = pq.top()[2];
			pq.pop();

			if (vis[cur][speed]) {
				continue;
			}

			vis[cur][speed] = 1;

			for (array<ll, 2> k : adj[cur]) {
				ll newS = min(speed, slow[k[0]]);

				if (cost[cur][speed] + k[1] * speed < cost[k[0]][newS]) {
					cost[k[0]][newS] = cost[cur][speed] + k[1] * speed;
					pq.push({-cost[k[0]][newS], k[0], newS});
				}
			}
		}

		ll ans = LLONG_MAX;

		for (int i = 1; i <= 1000; i++) {
			ans = min(ans, cost[n - 1][i]);
		}

		cout << ans << endl;
	}
}
