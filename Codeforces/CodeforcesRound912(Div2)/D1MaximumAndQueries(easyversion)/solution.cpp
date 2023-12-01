#include <bits/stdc++.h>

using namespace std;

int main() {
	vector<long long> bnums(62);
	vector<long long> bmask(62);

	long long num = 1;

	for (int i = 0; i < 62; i++) {
		bnums[i] = num;
		num = num << 1;
		bmask[i] = bnums[i];
		
		if (i != 0) {
			bmask[i] |= bmask[i - 1];
		}
	}

	int n, q;
	cin >> n >> q;

	vector<long long> an(n);
	for (int i = 0; i < n; i++) {
		cin >> an[i];
	}

	while (q--) {
		vector<long long> a(an);
		long long k;
		cin >> k;

		long long ans = 0;
		for (int b = 61; b >= 0; b--) {
			unsigned long long cost = 0;
			vector<long long> new_usage(an);

			bool fail = 0;
			for (int i = 0; i < a.size(); i++) {
				if ((a[i] & bnums[b]) != bnums[b]) {
					cost += bnums[b] - (a[i] & bmask[b]);
					new_usage[i] = 0;

					if (cost > k) {
						fail = 1;
						break;
					}
				}
			}
			
			if (!fail) {
				k -= cost;
				ans += bnums[b];
				a = new_usage;
			}
		}

		cout << ans << endl;
	}
}
