#include <bits/stdc++.h>

using namespace std;

int main() {
	int t;
	cin >> t;

	while (t--) {
		int n, m, d1, d2, d3, d4;
		cin >> n >> m;

		cout << "? 1 1" << endl;
		cin >> d1;

		if (d1 == 0) {
			cout << "! 1 1" << endl;
			continue;
		}

		cout << "? " << n << " " << m << endl;
		cin >> d2;

		if (d2 == 0) {
			cout << "! " << n << " " << m << endl;
			continue;
		}

		int diag1 = d1, diag2 = (n + m - 2) - d2;

		if (diag1 == diag2) {
			if (diag1 < n) {
				cout << "? " << diag1 << " 1" << endl;
			}
			else {
				cout << "? 1 " << m - 1 - d2 << endl;
			}
		}
	}
}
