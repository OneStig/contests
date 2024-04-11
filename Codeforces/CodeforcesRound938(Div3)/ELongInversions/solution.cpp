#include <bits/stdc++.h>

using namespace std;

int main() {
	int t;
	cin >> t;

	while (t--) {
		int n;
		string s;
		cin >> n >> s;

		int ans = 1;

		for (int k = n; k >= 1; k--) {
			bool flip = 0;
			vector<bool> unflip(n);

			for (int i = 0; i <= n - k; i++) {
				bool cur = (s[i] == '1') ^ flip;

				if (!cur) {
					flip = !flip;
					unflip[i + k - 1] = 1;
				}

				flip ^= unflip[i];
			}

			bool success = 1;
			for (int i = n - k + 1; i < n; i++) {
				bool cur = (s[i] == '1') ^ flip;

				if (!cur) {
					success = 0;
					break;
				}

				flip ^= unflip[i];
			}

			if (success) {
				ans = k;
				break;
			}
		}

		cout << ans << '\n';
	}
}

// 1011101
//  ----
// 1100001
//   ----
//
