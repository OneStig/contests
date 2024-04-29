#include <bits/stdc++.h>

using namespace std;

#define ll long long

void dfs(ll x, vector<vector<array<ll, 2>>>& adj, vector<ll>& pos) {
	for (auto& nb : adj[x]) {
		if (pos[nb[0]] == LLONG_MIN) {
			pos[nb[0]] = pos[x] + nb[1];
			dfs(nb[0], adj, pos);
		}
	}
}

int main() {
	int t;
	cin >> t;

	while (t--) {
		int n, m;
		cin >> n >> m;

		vector<vector<array<ll, 2>>> adj(n + 1);
		
		vector<array<ll, 3>> rules;

		while (m--) {
			ll a, b, d;
			cin >> a >> b >> d;
			adj[b].push_back({a, d});
			adj[a].push_back({b, -d});

			rules.push_back({a, b, d});
		}

		vector<ll> pos(n + 1, LLONG_MIN);

		for (int i = 1; i <= n; i++) {
			if (pos[i] == LLONG_MIN) {
				pos[i] = 0;
				dfs(i, adj, pos);
			}
		}

		bool yes = 1;

		for (auto& rule : rules) {
			if (pos[rule[0]] != pos[rule[1]] + rule[2]) {
				yes = 0;
				break;
			}
		}

		cout << (yes ? "YES" : "NO") << '\n';
	}
}
