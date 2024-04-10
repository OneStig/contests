#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, l, r, ql, qr;
	cin >> n >> l >> r >> ql >> qr;

	vector<int> w(n);

	for (int& i : w) {
		cin >> i;
	}

	vector<int> pfx(n);
	pfx[0] = w[0];

	for (int i = 1; i < n; i++) {
		pfx[i] = w[i] + pfx[i - 1];
	}

	vector<int> sfx(n);
	sfx[n - 1] = w[n - 1];

	for (int i = n - 2; i >= 0; i--) {
		sfx[i] = w[i] + sfx[i + 1];
	}

	int ans = min(sfx[0] * r + qr * (n - 1), pfx[n - 1] * l + ql * (n - 1));

	for (int i = 0; i + 1 < n; i++) {
		int lmoves = i + 1;
		int rmoves = n - lmoves;
		int curcost = pfx[i] * l + sfx[i + 1] * r;

		if (lmoves > rmoves) {
			curcost += (lmoves - rmoves - 1) * ql;
		}

		if (rmoves > lmoves) {
			curcost += (rmoves - lmoves - 1) * qr;
		}

		ans = min(ans, curcost);
	}

	cout << ans << "\n";
}

