#include <bits/stdc++.h>

using namespace std;

const int MX_N = 32000;

int main() {
	int t;
	cin >> t;


	vector<int> primes;
	vector<bool> isprime(MX_N + 1, 1);
	isprime[0] = 0, isprime[1] = 0;

	for (int i = 2; i <= MX_N; i++) {
		if (isprime[i] && i * i <= MX_N) {
			for (int j = i * i; j <= MX_N; j += i) {
				isprime[j] = 0;
			}
		}
	}

	for (int i = 2; i <= MX_N; i++) {
		if (isprime[i]) {
			primes.push_back(i);
		}
	}

	auto factors = [&primes](set<int>& seen, int x) {
		int ox = x;
		for (int p : primes) {
			if (x == 1 || p > sqrt(ox)) {
				break;
			}

			if (x % p == 0) {
				if (seen.find(p) != seen.end()) {
					return true;
				}

				if (seen.find(x / p) != seen.end()) {
					return true;
				}

				seen.insert(p);
				seen.insert(x / p);

				x /= p;
			}
		}

		return false;
	};

	while (t--) {
		int n;
		cin >> n;

		vector<int> a(n);

		set<int> hit;
		bool yes = 0;

		for (int i = 0; i < n; i++) {
			cin >> a[i];

			if (yes) {
				continue;
			}

			if (hit.find(a[i]) != hit.end()) {
				yes = 1;
			}

			hit.insert(a[i]);

			yes = yes || factors(hit, a[i]);
		}

		cout << (yes ? "YES" : "NO") << endl;
	}
}
