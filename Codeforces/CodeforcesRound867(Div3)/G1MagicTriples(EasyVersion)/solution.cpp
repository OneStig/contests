#include <bits/stdc++.h>
 
using namespace std;
 
#define ll long long

const ll MAX_A = 1e6;

ll freq[MAX_A + 1];
 
int main() {
	int t;
	cin >> t;
 
	while (t--) {
		int n;
		cin >> n;

		vector<ll> nums;
 
		for (int i = 0; i < n; i++) {
			ll a;
			cin >> a;

			if (!freq[a]++) {
				nums.push_back(a);
			}
		}
 
		ll ans = 0;
 
		for (ll x : nums) {
			// count b = 1;
			ans += freq[x] * (freq[x] - 1) * (freq[x] - 2);

			// count b = x;
			if (x != 1 && x * x <= MAX_A) {
				ans += freq[1] * freq[x] * freq[x * x];
			}

			// count everything else

			for (ll f = 2; f <= sqrt(x); f++) {
				if (!(x % f)) {
					// check f and x / f
					if (x * f <= MAX_A) {
						ans += freq[x / f] * freq[x] * freq[x * f];
					}

					if (f != x / f && x * x / f <= MAX_A) {
						ans += freq[f] * freq[x] * freq[x * x / f];
					}
				}
			}
		}

		for (ll x : nums) {
			freq[x] = 0;
		}
 
		cout << ans << '\n';
	}
}
