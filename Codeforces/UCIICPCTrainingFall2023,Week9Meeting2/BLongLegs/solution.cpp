#include <bits/stdc++.h>

using namespace std;

int main() {
	int t;
	cin >> t;

	while (t--) {
		int a, b;
		cin >> a >> b;

		int ans = INT_MAX;

		for (int k = 1; k <= 200005; k++) {
			ans = min(ans, k - 1 + (a + k - 1) / k + (b + k - 1) / k);
		}
		cout << ans << endl;
	}
}
