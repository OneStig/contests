#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main() {
	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;
		vector<ll> l(n), r(n), c(n);

		for (int i = 0; i < n; i++) {
			cin >> l[i];
		}

		for (int i = 0; i < n; i++) {
			cin >> r[i];
		}

		for (int i = 0; i < n; i++) {
			cin >> c[i];
		}

		sort(l.begin(), l.end());
		sort(r.begin(), r.end());
		sort(c.rbegin(), c.rend());

		int lx = 0, rx = 0;

		vector<ll> stk;
		vector<ll> inter;

		while (rx < n) {
			if (lx >= n || l[lx] > r[rx]) {
				inter.push_back(r[rx] - stk.back());
				stk.pop_back();
				rx++;
			}
			else {
				stk.push_back(l[lx]);
				lx++;
			}
		}

		sort(inter.begin(), inter.end());

		long long ans = 0;
		
		for (int i = 0; i < n; i++) {
			ans += inter[i] * c[i];
		}

		cout << ans << endl;
	}
}
