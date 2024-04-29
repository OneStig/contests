#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;

		set<int> coords;
		unordered_map<int, int> portals;

		for (int i = 0; i < n; i++) {
			int l, r, a, b;
			cin >> l >> r >> a >> b;
			coords.insert(-l);
			coords.insert(-b);

			if (portals[b] == 0 || l < portals[b]) {
				portals[b] = l;
			}
		}

		int q;
		cin >> q;

		vector<int> queries;

		for (int i = 0; i < q; i++) {
			int x;
			cin >> x;
			coords.insert(-x);
			queries.push_back(x);
		}

		unordered_map<int, int> ans;
		priority_queue<int> avail;

		for (auto p : coords) {
			p = -p;

			ans[p] = p;

			while (!avail.empty() && portals[avail.top()] > p) {
				avail.pop();
			}

			if (!avail.empty()) {
				ans[p] = ans[avail.top()];
			}

			if (portals[p]) {
				avail.push(p);
			}
		}

		for (int xq : queries) {
			cout << ans[xq] << ' ';
		}

		cout << '\n';
	}
}
