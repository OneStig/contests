#include <bits/stdc++.h>

using namespace std;

int main() {
	int t;
	cin >> t;

	while (t--) {
		int n, x;
		cin >> n >> x;

		vector<int> a(n);

		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}

		int mx_station = a[0];
		for (int i = 1; i < n; i++) {
			mx_station = max(mx_station, a[i] - a[i - 1]);
		}

		mx_station = max(mx_station, (x - a[n - 1]) * 2);

		cout << mx_station << endl;
	}
}
