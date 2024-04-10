#include <bits/stdc++.h>

using namespace std;

#define ll long long
const int MX_N = 1e6;

int main() {
	vector<bool> is_prime(MX_N + 1, 1);
	vector<int> primes;
	is_prime[1] = 0;
	for (int i = 2; i <= MX_N; i++) {
		if (is_prime[i]) {
			primes.push_back(i);
			if ((ll)i * i <= MX_N) {
				for (int j = i * i; j <= MX_N; j+= i) {
					is_prime[j] = 0;
				}
			}
		}
	}

	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;

		vector<int> a(n);

		for (int& i : a) {
			cin >> i;
		}

		vector<int> factors;

		if (is_prime[n]) {
			factors.push_back(n);
		}
		else {
			int tempn = n;
			for (int f : primes) {
				if (tempn == 1) {
					break;
				}

				if (tempn % f == 0) {
					factors.push_back(f);

					while (tempn % f == 0) {
						tempn /= f;
					}
				}
			}
		}

		int p = INT_MAX;
		int q = 1;

		for (int k: factors) {
			vector<int> cpa = a;
			vector<int> groups(k);

			int mx = INT_MIN;
			int mn = INT_MAX;

			for (int i = 0; i < n; i++) {
				groups[i % k] += cpa[i];
				mx = max(mx, groups[i % k]);
				mn = min(mn, groups[i % k]);
			}
			
			if ((double)mx / mn < (double)p / q) {
				p = mx;
				q = mn;
			}

			for (int i = 1; i < n ; i++) {
				groups[i] -= cpa[i];
				groups[i - 1] -= cpa[i - 1];
				swap(cpa[i], cpa[i - 1]);
				groups[i] += cpa[i];
				groups[i - 1] += cpa[i - 1];

				if ((double)mx / mn < (double)p / q) {
					p = mx;
					q = mn;
				}
			}
		}
	}
}
