#include <bits/stdc++.h>

using namespace std;

int main() {
	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;

		int ans = 0;

		vector<int> coins = {15, 10, 6, 3, 1};

		for (int x : coins) {
			if (n >= x) {
				ans += n / x;
				n %= x;
			}
		}

		cout << ans << '\n';
	}
}
