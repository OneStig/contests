#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main() {
	int n, m, s, t;
	cin >> n >> m >> s >> t;

	vector<vector<int>> adj(n);

	while (m--) {
		int a, b;
		cin >> a >> b;

		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	vector<ll> sq(n);
	set<int> bfs;
	bfs.insert(s);
	sq[s] = 1;

	for (int tm = 0; tm < t; tm++) {
		vector<ll> nsq(n);
		set<int> nbfs;

		for (auto it = bfs.begin(); it != bfs.end(); it++) {
			int cur = *it;

			for (int nxt : adj[cur]) {
				nsq[nxt] += sq[cur];
				nbfs.insert(nxt);
			}
		}

		bfs = nbfs;
		sq = nsq;
	}

	ll sum = 0;

	for (ll i : sq) {
		sum += i;
	}

	cout << sum << '\n';
}
