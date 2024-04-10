#include <bits/stdc++.h>

using namespace std;

const int MX = 200000;

array<int, 2> dp[100001];

void dfs(int x, int par, vector<vector<int>>& adj, vector<char>& type) {
	for (int nb : adj[x]) {
		if (nb == par) continue;

		dfs(nb, x, adj, type);
	}

	dp[x][0] = 0;
	dp[x][1] = 0;

	for (int nb : adj[x]) {
		if (nb == par) continue;

		dp[x][0] += min(dp[nb][0], dp[nb][1] + 1);
		dp[x][1] += min(dp[nb][1], dp[nb][0] + 1);
	}

	if (type[x] == 'P') {
		dp[x][1] = MX;
	}

	if (type[x] == 'S') {
		dp[x][0] = MX;
	}
}

int main() {
	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;

		vector<vector<int>> adj(n + 1);
		vector<char> type(n + 1);

		for (int i = 2; i <= n; i++) {
			int a;
			cin >> a;
			adj[i].push_back(a);
			adj[a].push_back(i);
		}

		for (int i = 1; i <= n; i++) {
			cin >> type[i];
		}

		dfs(1, -1, adj, type);

		cout << min(dp[1][0], dp[1][1]) << "\n";
	}
}
