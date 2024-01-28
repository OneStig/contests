#include <bits/stdc++.h>

using namespace std;

int main() {
	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;

		vector<int> b(n + 1);

		for (int i = 1; i <= n; i++) {
			cin >> b[i];
		}

		vector<int> pfx(n + 1);
		vector<int> sfx(n + 2);
		pfx[0] = INT_MIN, sfx[n + 1] = INT_MIN;
		
		for (int i = 1; i <= n; i++) {
			pfx[i] = max(pfx[i - 1], i + b[i]);
		}

		for (int i = n; i > 0; i--) {
			sfx[i] = max(sfx[i + 1], b[i] - i);
		}

		int ans = INT_MIN;
		for (int m = 2; m < n; m++) {
			int cur = b[m] + pfx[m - 1] + sfx[m + 1];
			ans = max(ans, cur);
		}

		cout << ans << endl;
	}
}
