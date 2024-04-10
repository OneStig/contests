#include <bits/stdc++.h>

using namespace std;

#define ll long long

void dijk(int start, vector<ll>& dist, vector<vector<array<int, 2>>>& adj, vector<int>& prev) {
	vector<bool> vis(adj.size());
	priority_queue<array<ll, 2>> pq;
	dist[start] = 0;
	pq.push({0, start});

	while (pq.size() > 0) {
		auto cur = pq.top();
		pq.pop();

		int curdist = -cur[0];
		int node = cur[1];

		if (vis[node]) {
			continue;
		}

		vis[node] = 1;

		for (auto nb : adj[node]) {
			if (curdist + nb[1] < dist[nb[0]]) {
				dist[nb[0]] = curdist + nb[1];
				prev[nb[0]] = node;
				pq.push({-dist[nb[0]], nb[0]});
			}
		}
	}
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;

	vector<array<int, 3>> edges(m);
	vector<vector<array<int, 2>>> adj(n + 1);

	vector<ll> sdist(n + 1, INT_MAX);
	vector<ll> ndist(n + 1, INT_MAX);

	for (int i = 0; i < m; i++) {
		cin >> edges[i][0] >> edges[i][1] >> edges[i][2];
		adj[edges[i][0]].push_back({edges[i][1], edges[i][2]});
		adj[edges[i][1]].push_back({edges[i][0], edges[i][2]});
	}

	vector<int> prev(n + 1, -1);

	dijk(1, sdist, adj, prev);

	if (sdist[n] == INT_MAX) {
		cout << -1 << '\n';
		return 0;
	}

	ll ans = sdist[n];
	// backtrack to find used edges
	
	vector<set<int>> used_edges(n + 1);
	int cur = n;

	while (cur != 1) {
		used_edges[cur].insert(prev[cur]);
		used_edges[prev[cur]].insert(cur);

		cur = prev[cur];
	}

	dijk(n, ndist, adj, prev);

	ll ans2 = LLONG_MAX;

	for (int i = 0; i < m; i++) {
		int x = edges[i][0];
		int y = edges[i][1];
		int weight = edges[i][2];

		if (used_edges[x].find(y) != used_edges[x].end()) {
			continue;
		}

		if (sdist[x] != INT_MAX && ndist[y] != INT_MAX) {
			ans2 = min(ans2, sdist[x] + ndist[y] + weight);
		}

		if (sdist[y] != INT_MAX && ndist[x] != INT_MAX) {
			ans2 = min(ans2, sdist[y] + ndist[x] + weight);
		}
	}

	if (ans2 == LLONG_MAX) {
		cout << -1 << "\n";
	}
	else {
		cout << ans + ans2 << "\n";
	}
}
