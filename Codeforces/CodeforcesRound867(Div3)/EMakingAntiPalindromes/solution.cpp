#include <bits/stdc++.h>

using namespace std;

int main() {
	int t;
	cin >> t;

	while (t--) {
		int n;
		string s;
		cin >> n >> s;

		if (n % 2) {
			cout << -1 << "\n";
			continue;
		}

		vector<int> freq(26);

		bool fail = 0;
		for (int i = 0; i < n; i++) {
			if (++freq[s[i] - 'a'] > n / 2) {
				fail = 1;
				break;
			}
		}

		if (fail) {
			cout << -1 << endl;
			continue;
		}

		int bad = 0;
		vector<int> pfreq(26);
		for (int i = 0; i < n / 2; i++) {
			if (s[i] == s[n - i - 1]) {
				bad++;
				pfreq[s[i] - 'a']++;
			}
		}

		int ans = (bad + 1) / 2;
		for (int i = 0; i < 26; i++) {
			if (pfreq[i] > bad - pfreq[i]) {
				ans = pfreq[i];
				break;
			}
		}

		cout << ans << "\n";
	}
}
