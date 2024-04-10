#include <bits/stdc++.h>

using namespace std;

int main() {
	int t;
	cin >> t;

	while (t--) {
		string s;
		cin >> s;
		int n = s.size();

		int ans = 0;
		for (int i = 1; i <= n / 2; i++) {
			int cons = 0;
			for (int j = 0; j + i < n; j++) {
				if (s[j] == s[j + i] || s[j] == '?' || s[j + i] == '?') {
					cons++;
				}
				else {
					cons = 0;
				}

				if (cons >= i) {
					ans = i;
				}
			}
		}

		cout << ans * 2 << '\n';
	}
}
