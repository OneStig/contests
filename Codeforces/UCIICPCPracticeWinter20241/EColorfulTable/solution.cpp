#include <bits/stdc++.h>

using namespace std;

int main() {
	int t;
	cin >> t;

	while (t--) {
		int n, k;
		cin >> n >> k;

		vector<int> a(n);
		vector<bool> seen(k + 1);

		int lb = 0, rb = n - 1;

		for (int& i : a) {
			cin >> i;
			seen[i] = 1;
		}

		for (int i = 1; i <= k; i++) {
			if (i != 1) {
				cout << " ";
			}

			if (seen[i]) {
				cout << 2 * (rb - lb + 1);

				while (lb < n && a[lb] <= i) {
					lb++;
				}

				while (rb >= 0 && a[rb] <= i) {
					rb--;
				}
			}
			else {
				cout << 0;
			}
		}

		cout << endl;
	}
}
