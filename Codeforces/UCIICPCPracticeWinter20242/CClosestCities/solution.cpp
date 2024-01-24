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

		int m;

		vector<int> fwd(n);

		fwd[0] = 0;
		fwd[1] = 1;

		for (int i = 1; i < n - 1; i++) {
			if (a[i + 1] - a[i] < a[i] - a[i - 1]) {
				fwd[i + 1] = 1;
			}
			else {
				fwd[i + 1] = a[i + 1] - a[i];
			}

			fwd[i + 1] += fwd[i];
		}

		vector<int> bkd(n);

		bkd[n - 1] = 0;
		bkd[n - 2] = 1;

		for (int i = n - 2; i > 0; i--) {
			if (a[i] - a[i - 1] < a[i + 1] - a[i]) {
				bkd[i - 1] = 1;
			}
			else {
				bkd[i - 1] = a[i] - a[i - 1];
			}

			bkd[i - 1] += bkd[i];
		}

		cin >> m;

		while (m--) {
			int x, y;
			cin >> x >> y;

			if (y > x) {
				cout << (fwd[y - 1] - fwd[x - 1]) << endl;
			}
			else {
				cout << (bkd[y - 1] - bkd[x - 1]) << endl;
			}
		}
	}
}
