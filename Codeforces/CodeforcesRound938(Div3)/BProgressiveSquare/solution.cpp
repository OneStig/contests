#include <bits/stdc++.h>

using namespace std;

int main() {
	int t;
	cin >> t;

	while (t--) {
		int n, c, d;
		cin >> n >> c >> d;

		map<int, int> freq;

		int mx = INT_MIN;
		for (int i = 0; i < n * n; i++) {
			int b;
			cin >> b;

			freq[b]++;
			mx = max(mx, b);
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				freq[mx - d * i - c * j]--;
			}
		}

		bool ans = 1;

		for (auto x : freq) {
			if (x.second != 0) {
				ans = 0;
				break;
			}
		}

		cout << (ans ? "YES" : "NO") << '\n';
	}
}
