#include <bits/stdc++.h>

using namespace std;

int main() {
	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;
		long long a = 0;

		for (int i = 0; i < n; i++) {
			long long b;
			cin >> b;

			a += b;
		}

		long long test = (long long)(sqrt(a));
		cout << (test * test == a ? "YES" : "NO") << endl;
	}
}
