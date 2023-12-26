#include <bits/stdc++.h>

using namespace std;

int main() {
	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;
		vector<long long> a(n);

		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}

		long long k = 1;

		while (1) {
			k *= 2;

			unordered_set<long long> x;

			for (int j = 0; j < n; j++) {
				x.insert(a[j] % k);

				if (x.size() > 2) {
					break;
				}
			}

			if (x.size() == 2) {
				break;
			}
		}

		cout << k << endl;
	}
}
