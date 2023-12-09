#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> adj;
vector<bool> vis;

int dist, mx;

void dfs(int x, int ply) {
	vis[x] = 1;

	if (ply > dist) {
		dist = ply;
		mx = x;
	}

	for (int a : adj[x]) {
		if (!vis[a]) {
			dfs(a, ply + 1);
		}
	}
}

int main() {
	int n;
	cin >> n;
	
	adj.resize(n + 1);
	vis.resize(n + 1);

	for (int i = 1; i < n; i++) {
		int a, b;
		cin >> a >> b;

		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	dist = 0;
	mx = 1;

	dfs(1, 0);

	dist = 0;
	vis = vector<bool>(n + 1, 0);

	dfs(mx, 0);

	cout << dist << endl;
}
