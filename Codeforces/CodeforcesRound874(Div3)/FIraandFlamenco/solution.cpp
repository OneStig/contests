#include <bits/stdc++.h>

using namespace std;

#define ll long long
const int MOD = 1e9 + 7;

int main() {
	int t;
	cin >> t;

	while (t--) {
		int n, m;
		cin >> n >> m;

		vector<int> a(n);
		map<int, ll> freq;

		vector<int> unq;

		for (int& i : a) {
			cin >> i;
			freq[i]++;

			if (freq[i] == 1) {
				unq.push_back(i);
			}
		}

		sort(unq.begin(), unq.end());

		int con = 1;

		vector<bool> possib(unq.size());

		if (m == 1) {
			possib[0] = 1;
		}

		for (int i = 1; i < unq.size(); i++) {
			if (unq[i] == unq[i - 1]) {
				con++;
			}
			else {
				con = 1;
			}

			if (con >= m) {
				possib[i] = 1;
			}
		}

		ll ans = 0;
		ll cur = 1;

		for (int i = 0; i < m - 1; i++) {
			cur *= freq[unq[i]];
			cur %= MOD;
		}

		for (int i = m - 1; i < unq.size(); i++) {
			cur *= freq[unq[i]];
			cur %= MOD;

			if (possib[i]) {
				cout << i << " ";
				ans += cur;
				ans %= MOD;
			}

			cur /= freq[unq[i - m + 1]];
		}

		cout << ans << endl;
	}
}
