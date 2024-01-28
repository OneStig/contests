#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main() {
	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;

		vector<vector<ll>> a;

		for (int i = 0; i < n; i++) {
			int x;
			cin >> x;

			if (x == 0 || a.size() == 0) {
				a.push_back(vector<ll>());
			}

			a.back().push_back(x);
		}

		ll ans = 0;

		for (int i = 0; i < a.size(); i++) {
			vector<ll> pfx(a[i].size());
			map<ll, int> freq;

			freq[a[i][0]] = 1;
			pfx[0] = a[i][0];

			int mx = 1;

			for (int j = 1; j < a[i].size(); j++) {
				pfx[j] = pfx[j - 1] + a[i][j];
				mx = max(mx, ++freq[pfx[j]]);
			}

			if (a[i][0] == 0) {
				ans += mx;
			}
			else {
				ans += freq[0];
			}
		}

		cout << ans << endl;
	}
}
