#include <bits/stdc++.h>

using namespace std;

int main() {
	int t;
	cin >> t;

	while (t--) {
		int n, k;
		cin >> n >> k;
		k--;

		vector<int> a(n);

		for (int& i : a) {
			cin >> i;
		}

		int cow = a[k];
		int bad = -1;

		for (int i = 0; i < k; i++) {
			if (a[i] > cow) {
				bad = i;
				break;
			}
		}

		swap(a[0], a[k]);

		int ans = 0;
		for (int i = 1; i < n; i++) {
			if (a[i] > cow) {
				break;
			}

			ans++;
		}

		if (bad > 0) {
			swap(a[0], a[k]);
			swap(a[k], a[bad]);
			int newAns = 1;
			for (int i = bad + 1; i < n; i++) {
				if (a[i] > cow) {
					break;
				}

				newAns++;
			}

			ans = max(ans, newAns);
		}

		cout << ans << '\n';
	}
}
