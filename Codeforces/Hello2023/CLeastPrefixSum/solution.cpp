#include <bits/stdc++.h>

using namespace std;

int main() {
	int t;
	cin >> t;

	while (t--) {
		int n, m;
		cin >> n >> m;
		m--;

		vector<int> a(n);

		for (int& i : a) {
			cin >> i;
		}

		int ans = (a[m] > 0 ? 1 : 0);

		int pfx = 0;
	}
}
