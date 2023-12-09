#include <bits/stdc++.h>

using namespace std;

int n;
vector<array<int, 2>> seg;

bool check(int k) {
	int l = 0, r = 0;

	for (int i = 0; i < seg.size(); i++) {
		l = max(l - k, seg[i][0]);
		r = min(r + k, seg[i][1]);

		if (l > r) {
			return false;
		}
	}

	return true;
}

int main() {
	int t;
	cin >> t;

	while (t--) {
		cin >> n;
		seg.resize(n);

		int r = 0;
		for (int i = 0; i < n; i++) {
			cin >> seg[i][0] >> seg[i][1];
			r = max(r, seg[i][1]);
		}

		int l = 0;
		while (r > l) {
			int k = (r + l) / 2;
			bool c = check(k);

			if (c)
				r = k;
			else
				l = k + 1;
		}

		cout << r << endl;
	}
}
