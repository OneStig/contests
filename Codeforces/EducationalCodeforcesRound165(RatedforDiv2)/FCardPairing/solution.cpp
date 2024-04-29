#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, k;
	cin >> n >> k;

	vector<int> a(n);
	for (int& x : a) {
		cin >> x;
	}

	int ans = 0;
	if (k == 2) {
		for (int i = 0; i < n / 2; i += 2)  {
			ans += a[i] == a[i + 1];
		}

		cout << ans << '\n';
		return 0;
	}

	int pairs = 0;
	unordered_set<int> ones;

	for (int i = 0; i < k; i++) {
		if (ones.contains(a[i])) {
			ones.erase(a[i]);
			pairs++;
		}
	}
}
