#include <bits/stdc++.h>

using namespace std;

int main() {
	int t;
	cin >> t;

	while (t--) {
		int n, k;
		cin >> n >> k;
		int x = 4 * n - 2;

		int ans;

		if (k < 2 * (2 * n - 2)) {
			ans = (k + 1) / 2;
		}
		else {
			ans = 2 * n - 2 + (k - 2 * (2 * n - 2));
		}


		cout << ans << endl;
	}
}
