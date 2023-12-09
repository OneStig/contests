#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int>> bt;
string dirs;

int dfs(int x, vector<int>& ops) {
	if (!bt[x].first && !bt[x].second) {
		return ops[x];
	}

	int ret = INT_MAX;

	if (bt[x].first) {
		ops[bt[x].first] = ops[x];

		if (dirs[x - 1] != 'L') {
			ops[bt[x].first]++;
		}

		ret = min(ret, dfs(bt[x].first, ops));
	}

	if (bt[x].second) {
		ops[bt[x].second] = ops[x];

		if (dirs[x - 1] != 'R') {
			ops[bt[x].second]++;
		}

		ret = min(ret, dfs(bt[x].second, ops));
	}

	return ret;
}

int main() {
	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;
		cin >> dirs;

		bt.resize(n + 1);

		vector<int> changes(n + 1);

		for (int i = 1; i <= n; i++) {
			int l, r;
			cin >> l >> r;

			bt[i] = {l, r};
		}

		int ans = dfs(1, changes);	
		cout << ans << endl;
	}
}

