#include <bits/stdc++.h>

using namespace std;

int main() {
	int t;
	cin >> t;

	while (t--) {
		int n, m;
		cin >> n >> m;

		vector<set<int>> adja(n);
		vector<set<int>> adjb(200002);

		for (int i = 0; i < m; i++) {
			int u, v, c;
			cin >> u >> v >> c;
			u--, v--;

			adja[u].insert(c);
			adja[v].insert(c);
			adjb[c].insert(u);
			adjb[c].insert(v);
		}

		vector<int> dista(n, -1), distb(200002, -1);

		int b, e;
		cin >> b >> e;
		b--, e--;

		if (b == e) {
			cout << 0 << '\n';
			continue;
		}

		queue<pair<int, bool>> q;
		q.push({b, 0});
		dista[b] = 0;

		while (!q.empty()) {
			int cur = q.front().first;
			bool side = q.front().second;
			q.pop();

			if (side == 0) {
				if (cur == e) {
					break;
				}

				for (auto nb : adja[cur]) {
					if (distb[nb] == -1) {
						distb[nb] = dista[cur] + 1;
						q.push({nb, 1});
					}
				}
			}
			else {
				for (auto nb : adjb[cur]) {
					if (dista[nb] == -1) {
						dista[nb] = distb[cur] + 1;
						q.push({nb, 0});
					}
				}
			}
		}

		cout << dista[e] / 2 << '\n';
	}
}
