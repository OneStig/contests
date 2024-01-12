#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m, h, t;
	cin >> n >> m;

	multiset<int> p;

	for (int i = 0; i < n; i++) {
		cin >> h;

		p.insert(h);
	}

	while (m--) {
		cin >> t;

		auto it = p.upper_bound(t);

		if (it == p.begin()) {
			cout << -1 << endl;
		}
		else {
			it--;
			cout << *it << endl;
			p.erase(it);
		}
	}
}
