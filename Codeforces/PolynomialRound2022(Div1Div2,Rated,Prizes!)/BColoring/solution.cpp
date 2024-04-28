#include <bits/stdc++.h>

using namespace std;

int main() {
	int t;
	cin >> t;

	while (t--) {
		int n, m, k;
		cin >> n >> m >> k;

		int rep = (n + k - 1) / k;
		int full{};
		bool fail = 0;

		while (m--) {
			int a;
			cin >> a;

			if (a > rep) {
				fail = 1;
			}
			else if (a == rep) {
				full++;
			}
		}

		cout << (fail || (n % k != 0 && full > n % k) ? "NO" : "YES") << '\n';
	}
}
