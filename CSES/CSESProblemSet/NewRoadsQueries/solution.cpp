#include <bits/stdc++.h>

using namespace std;

struct DSU {
	vector<int> e;

	void init(int N) {
		e = vector<int>(N, -1);
	}

	int get(int x) { return e[x] < 0 ? x : e[x] = get(e[x]); }

	bool same_set(int a, int b) { return get(a) == get(b); }

	int size(int x) { return -e[get(x)]; }

	bool unite(int x, int y) {
		x = get(x), y = get(y);
		if (x == y) return false;
		if (e[x] > e[y]) swap(x, y);
		e[x] += e[y];
		e[y] = x;
		return true;
	}
};

int main() {
	int n, m, q;
	cin >> n >> m >> q;
	
	DSU cities;
	cities.init(n);

	int ans = -1;

	for (int i = 1; i <= n; i++) {
		int a, b;
		cin >> a >> b;

		if (ans == -1) {
			continue;
		}


	}
}
