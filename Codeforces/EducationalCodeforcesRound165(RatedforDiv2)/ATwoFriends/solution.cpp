#include <bits/stdc++.h>

using namespace std;

int main() {
	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;

		vector<int> a(n);
		for (int& i : a) {
			cin >> i;
		}

		int ans = 3;
		for (int i = 0; i < n; i++) {
			for (int j = 1; j < n; j++) {
				if (a[i] == j + 1 && a[j] == i + 1) {
					ans = 2;
					break;
				}
			}
		}

		cout << ans << '\n';
	}
}
