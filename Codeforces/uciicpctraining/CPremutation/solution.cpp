#include <bits/stdc++.h>

using namespace std;

int main() {
	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;

		vector<int> mxpos(n + 1, INT_MIN);
		vector<int> mnpos(n + 1, INT_MAX);
		vector<int> ans(n + 1);

		for (int i = 0; i < n; i++) {
			vector<int> perm(n);

			for (int j = 1; j < n; j++) {
				cin >> perm[j];

				mxpos[perm[j]] = max(mxpos[perm[j]], j);
				mnpos[perm[j]] = min(mnpos[perm[j]], j);
			}
		}

		for (int i = 1; i <= n; i++) {
			if (mxpos[i] == mnpos[i] && mxpos[i] != 1) {
				ans[n] = i;
			}
			else {
				ans[mxpos[i]] = i;
			}
		}

		for (int i = 1; i <= n; i++) {
			cout << ans[i] << " ";
		}

		cout << "\n";
	}
}
