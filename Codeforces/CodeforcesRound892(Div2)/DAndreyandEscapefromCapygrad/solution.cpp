#include <bits/stdc++.h>

using namespace std;

int main() {
	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;

		set<int> coords;

		vector<array<int, 3>> portals;
		
		for (int i = 0; i < n; i++) {
			int l, r, a, b;
			cin >> l >> r >> a >> b;
			coords.insert(l);
			coords.insert(b);

			portals.push_back({});
		}
	}
}
