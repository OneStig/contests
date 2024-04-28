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

	while (t--) {
		int n;
		cin >> n;

		unordered_set<int> factors;
		int a;
		bool yes = 0;

		while (n--) {
			cin >> a;

			if (!yes) {
				for (int i = 0; i < primes.size(); i++) {
					if (a == 1) {
						break;
					}

					if (a % primes[i] == 0) {
						if (factors.find(primes[i]) != factors.end()) {
							yes = 1;
							break;
						}
						factors.insert(primes[i]);

						while (a % primes[i] == 0) {
							a /= primes[i];
						}
					}
				}

				if (a != 1) {
					if (factors.find(a) != factors.end()) {
						yes = 1;
					}
					else {
						factors.insert(a);
					}
				}
			}
		}

		cout << (yes ? "YES" : "NO") << '\n';
		// 402122038 603183057
		// 2, 201061019
		// 3, 201061019
	}
}
