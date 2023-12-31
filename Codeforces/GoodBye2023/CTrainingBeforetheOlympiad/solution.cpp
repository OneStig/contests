#include <bits/stdc++.h>

using namespace std;

int main() {
	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;

		int parity[2];

		parity[0] = 0;
		parity[1] = 0;

		long long sum;
		cin >> sum;

		parity[sum % 2]++;

		cout << sum;

		for (int i = 1; i < n; i++) {
			int a;
			cin >> a;
			sum += a;
			parity[a % 2]++;

			int red = 0;

			if (parity[0] > 0 || parity[1] > 1) {
				red = parity[1] / 3;
				
				if (parity[1] % 3 == 1) {
					red++;
				}
			}

			cout << " " << sum - red;
		}
		cout << endl;
	}
}
