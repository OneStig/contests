#include <bits/stdc++.h>

using namespace std;

int main() {
	int t;
	cin >> t;

	while (t--) {
		int n, m, k;
		cin >> n >> m >> k;

		vector<int> a(n), b(m);

		for (int& i : a) {
			cin >> i;
		}

		map<int, int> freq;

		for (int& i : b) {
			cin >> i;
			freq[i]++;
		}

		int ans = 0;

		int cur = 0;
		for (int i = 0; i < m; i++) {
			if (freq[a[i]] > 0) {
				cur++;
			}

			freq[a[i]]--;
		}

		if (cur >= k) {
			ans = 1;
		}

		for (int i = m; i < n; i++) {
			if (freq[a[i]] > 0) {
				cur++;
			}
			freq[a[i]]--;

			if (freq[a[i - m]] >= 0) {
				cur--;
			}
			
			freq[a[i - m]]++;

			ans += cur >= k;
		}

		cout << ans << '\n';
	}
}
