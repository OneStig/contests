#include <bits/stdc++.h>

using namespace std;

int main() {
	int t;
	cin >> t;

	while (t--) {
		int n, k;
		cin >> n >> k;

		bool sorted = 1;
		int last = INT_MIN;
		for (int i = 0; i < n; i++) {
			int a;
			cin >> a;

			if (a < last) {
				sorted = 0;
			}
			last = a;
		}

		cout << (sorted || k > 1 ? "YES" : "NO") << endl;
	}
}
