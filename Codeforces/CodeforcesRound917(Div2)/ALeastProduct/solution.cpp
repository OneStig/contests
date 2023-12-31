#include <bits/stdc++.h>

using namespace std;

int main() {
	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;

		int a;
		int ans = 1;

		for (int i = 0; i < n; i++) {
			cin >> a;
			if (a) {
				ans *= abs(a) / a;
			}
			else {
				ans = 0;
			}
		}

		if (ans > 0) {
			cout << 1 << endl << "1 0" << endl;
		}
		else {
			cout << 0 << endl;
		}
	}
}
