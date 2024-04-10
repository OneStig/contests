#include <bits/stdc++.h>

using namespace std;

const int B = 18;

vector<int> subtree;
vector<int> depth;
vector<int> parent;
vector<array<int, B>> lift;
vector<vector<int>> adj;

int goup(int x, int k) {
	// move x up by k

	for (int i = 0; k; i++, k /= 2) {
		if (k & 1) {
			x = lift[x][i];
		}
	}

	return x;
}

int solve(int a, int b) {
	int origa = a, origb = b;
	int aup = 0;
	int bup = 0;

	if (depth[a] > depth[b]) {
		aup = depth[a] - depth[b];
		a = goup(a, aup);
	}

	if (depth[b] > depth[a]) {
		bup = depth[b] - depth[a];
		b = goup(b, bup);
	}

	int total = aup + bup;

	if (a != b) {
		int amt = 1 << (B - 1);
		for (int i = B - 1; i >= 0; i--) {
			if (lift[a][i] != lift[b][i]) {
				a = lift[a][i];
				b = lift[b][i];
				aup += amt;
				bup += amt;
			}

			amt >>= 1;
		}
		total = aup + bup + 2;
	}

	if (total % 2 == 1) {
		return 0;
	}

	if (aup == bup) {
		return subtree[0] - subtree[a] - subtree[b];
	}

	if (aup > bup) {
		int mid = goup(origa, total / 2);
		int sub = goup(origa, total / 2 - 1);

		return subtree[mid] - subtree[sub];
	}
	else {
		int mid = goup(origb, total / 2);
		int sub = goup(origb, total / 2 - 1);

		return subtree[mid] - subtree[sub];
	}
}

void dfs(int x, int p) {
	subtree[x] = 1;
	depth[x] = depth[p] + 1;
	parent[x] = p;
	lift[x][0] = p;

	for (int i = 1; i < B; i++) {
		lift[x][i] = lift[lift[x][i - 1]][i - 1];
	}

	for (int nb : adj[x]) {
		if (nb != p) {
			dfs(nb, x);
			subtree[x] += subtree[nb];
		}
	}
}

int main() {
	int n;
	cin >> n;

	depth.resize(n);
	parent.resize(n);
	lift.resize(n);
	adj.resize(n);
	subtree.resize(n);

	for (int i = 1; i < n; i++) {
		int a, b;
		cin >> a >> b;
		a--, b--;

		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	depth[0] = -1;
	dfs(0, 0);

	int m;
	cin >> m;

	while (m--) {
		int a, b;
		cin >> a >> b;
		a--, b--;

		if (a == b) {
			cout << n << '\n';
		}
		else {
			cout << solve(a, b) << '\n';
		}
	}
}
