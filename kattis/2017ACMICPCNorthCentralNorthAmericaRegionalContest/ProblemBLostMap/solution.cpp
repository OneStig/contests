#include <bits/stdc++.h>

using namespace std;

struct DSU {
	vector<int> e;

	void init(int n) { e = vector<int>(n, -1); }
	int find(int x) { return (e[x] < 0 ? x : e[x] = find(e[x])); }
	int size(int x) { return -e[find(x)];	}
	bool is_same(int a, int b) { return find(a) == find(b); }

	bool unite(int a, int b) {
		a = find(a), b = find(b);
		if (a == b)
			return false;
		if (e[a] > e[b])
			swap(a, b);
		e[a] += e[b];
		e[b] = a;
		return true;
	}
};

int main() {
	int n;
	cin >> n;

	priority_queue<array<int, 3>> edges;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int x;
			cin >> x;

			if (j > i) {
				edges.push({-x, i, j});
			}
		}
	}

	DSU village;
	village.init(n);

	vector<array<int, 2>> ans;

	while (!edges.empty()) {
		auto cur = edges.top();
		edges.pop();

		if (!village.is_same(cur[1], cur[2])) {
			village.unite(cur[1], cur[2]);
			ans.push_back({cur[1], cur[2]});

			if (village.size(cur[1]) == n) {
				break;
			}
		}
	}

	for (auto& uv : ans) {
		cout << uv[0] + 1 << " " << uv[1] + 1 << "\n";
	}
}
