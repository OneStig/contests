#include <bits/stdc++.h>

using namespace std;

int main() {
	int t;
	cin >> t;

	while (t--) {
		int n, k;
		cin >> n >> k;

		if (n == k) {
			while (n--) {
				cout << 1 << ' ';
			}
		}
		else if (k == 1) {
			for (int i = 1; i <= n; i++) {
				cout << i << ' ';
			}
		}
		else {
			cout << -1;
		}


		cout << '\n';
	}
}
