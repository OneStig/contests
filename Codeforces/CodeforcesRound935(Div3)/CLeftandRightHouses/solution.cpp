#include <bits/stdc++.h>

using namespace std;

#define ld long double

int main() {
	int t;
	cin >> t;

	while (t--) {
		int n;
		string s;

		cin >> n >> s;

		vector<int> a(n + 1);
		vector<int> pfx(n + 1);

		int total = 0;
		for (int i = 1; i <= n; i++) {
			a[i] = s[i - 1] - '0';
			total += a[i];
			pfx[i] = pfx[i - 1] + a[i];
		}

		int ans = -1;
		ld best = 1e10;
		for (int i = 0; i <= n; i++) {
			if (pfx[i] * 2 <= i && (total - pfx[i]) * 2 >= n - i) {
				if (best > abs((ld)n / 2 - i)) {
					best = abs((ld)n / 2 - i);
					ans = i;
				}
			}
		}

		cout << ans << '\n';
	}
}
