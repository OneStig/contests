#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main() {
	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;

		ll sum{}, ans{}, peak{}, dip{};

		for (int i = 0; i < n; i++) {
			ll a;
			cin >> a;

			sum += a;
			peak = max(peak, sum);

			if (peak - sum > dip) {
				dip = peak - sum;
				ans = peak;
			}
		}

		cout << ans << '\n';
	}
}
