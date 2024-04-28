#include <bits/stdc++.h>

using namespace std;

int main() {
	int t;
	cin >> t;

	while (t--) {
		int n, m;
		cin >> n >> m;

		vector<int> a(n), b;

		for (int& i : a) {
			cin >> i;
		}

		b = a;
		sort(b.begin(), b.end());

		int wins = 0;
		int sum = 0;

		for (int i = 0; i < n; i++) {
			if (sum + b[i] <= m) {
				wins++;
				sum += b[i];
			}
			else {
				break;
			}
		}

		if (wins == n) {
			cout << 1 << '\n';
			continue;
		}

		if (wins == 0) {
			cout << n + 1 << '\n';
			continue;
		}

		int wins2 = 0;
		int sum2 = 0;

		if (a[wins] <= m) {
			sum2 += a[wins];
			wins2++;

			a[wins] = INT_MAX;
			sort(a.begin(), a.end());

			for (int i = 0; i < n; i++) {
				if (sum2 + a[i] <= m) {
					wins2++;
					sum2 += a[i];
				}
				else {
					break;
				}
			}
		}


		if (wins == wins2) {
			cout << n - wins << '\n';
		}
		else {
			cout << n - wins + 1 << '\n';
		}
	}
}
