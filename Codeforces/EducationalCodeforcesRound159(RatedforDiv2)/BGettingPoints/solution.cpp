#include <bits/stdc++.h>

using namespace std;

int main() {
	int tc;
	cin >> tc;

	while (tc--) {
		long long n, p, l, t;

		cin >> n >> p >> l >> t;

		int le = 0, ri = n;

		while (ri - le > 1) {
			long long m = (le + ri) / 2;
			long long pts = m * l + min(2 * m, (n - 1) / 7 + 1) * t;

			if (pts >= p) {
				ri = m;
			}
			else {
				le = m;
			}
		}

		cout << n - ri << endl;
	}
}
