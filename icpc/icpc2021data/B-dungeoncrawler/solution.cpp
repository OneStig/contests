#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2001;

vector<array<int, 2>> adj[MAXN];

array<int, 2> eind[MAXN][MAXN];
vector<int> euler[MAXN];
int vis[MAXN];

bool subtree(int n, int a, int b) {
	// for root n, return is a in b inclusive
	
	return eind[n][b][0] <= eind[n][a][0] && eind[n][a][1] <= eind[n][b][1];
}

void dfs(int x, int start) {
	vis[x] = 1;
	eind[start][x][0] = euler[start].size();
	euler[start].push_back(x);

	for (int i = 0; i < adj[x].size(); i++) {
		int nxt = adj[x][i][0];
		
		if (!vis[nxt]) {
			dfs(nxt, start);
		}
	}

	eind[start][x][1] = euler[start].size();
	euler[start].push_back(x);
}

int main() {
	int n, q; // n <= 2,000 : q <= 200,000
	cin >> n >> q;

	long long tw = 0;

	for (int i = 1; i < n; i++) {
		int u, v, w;
		cin >> u >> v >> w;

		adj[u].push_back({v, w});
		adj[v].push_back({u, w});

		tw += w;
	}

	unordered_set<int> leaves;

	// construct eulerian ordering, rooted at every n.

	// in order for this to be possible, start node
	// and key node must be in the same subtree of the children
	// of the trap, otherwise traversing from start to key
	// would require passing through the trap cell first

	for (int i = 1; i <= n; i++) {
		memset(vis, 0, sizeof(vis));
		dfs(i, i);
	}

	while (q--) {
		int s, k, t;
		cin >> s >> k >> t;

		//bool possib = (eind[t][k][0] < eind[t][s][0] && eind[t][s][1] < eind[t][k][1]) ||
						//(eind[t][s][0] < eind[t][k][0] && eind[t][k][1] < eind[t][s][1]);

		bool possib = 0;

		for (int i = 0; i < adj[t].size(); i++) {
			bool start_tree = subtree(t, s, adj[t][i][0]);
			bool key_tree = subtree(t, k, adj[t][i][0]);

			if (start_tree && key_tree) {
				possib = 1;
				break;
			}
		}


		if (possib) {
			cout << tw << endl;
			continue;
		}

		cout << "IMPOSSIBLE" << endl;
	}
}
