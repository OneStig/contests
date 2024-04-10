#include <bits/stdc++.h>

using namespace std;

int main() {
	int t;
	cin >> t;

	while (t--) {
		int q;
		cin >> q;

		int lb = 1, ub = INT_MAX;

		while (q--) {
			int type, a, b;
			cin >> type;

			if (type == 1) {
				int n;
				cin >> n;

				int curmn = (n - 1) * (a - b) + 1;
				int curmx = (n - 1) * (a - b) + a;

				if (curmn >= lb && curmx <= ub) {
					lb = max(lb, curmn);
					ub = min(ub, curmx);
					cout << 1 << " ";
				}
				else {
					cout << 0 << " ";
				}
			}
			else {
				int a, b;
				cin >> a >> b;

				int lbdays = 1;

				if (lb > a) {
					lbdays += (lb - b + 1) / (a - b);
				}

				int ubdays = 1;

				if (ub > a) {
					ubdays += (ub - b + 1) / (a - b);
				}

				if (ubdays == lbdays) {
					cout << ubdays << " ";
				}
				else {
					cout << "-1 ";
				}
			}
		}

		cout << "\n";
	}
}
