#include <bits/stdc++.h>

using namespace std;

int main() {
	int t;
	cin >> t;

	while (t--) {
		int n;
		string s;
		cin >> n >> s;

		int ind = n - 1;
		int lb = -1;
		for (int i = 0; i < n; i++) {
			if (s[i] == 'A') {
				if (ind == n - 1) {
					ind = i;
				}
			} else {
				lb = i;
			}
		}
		if (lb < ind) {
			cout << 0 << endl;
		}
		else {
			cout << lb - ind << endl;
		}
	}
}
