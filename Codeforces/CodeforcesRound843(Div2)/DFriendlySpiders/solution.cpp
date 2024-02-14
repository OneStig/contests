#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
#include <bits/debug.h>
#endif

#define ll long long

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	vector<int> a(n);

	ll mx = INT_MIN;
	for (int& i : a) {
		cin >> i;
		mx = max(mx, (ll)i);
	}

	int s, t;
	cin >> s >> t;

	if (s == t) {
		cout << 1 << endl;
		cout << s << endl;
		return 0;
	}

	s--, t--;

	vector<bool> isprime(mx + 1, 1);
	isprime[1] = 0;
	vector<int> primes;

	for (ll i = 2; i <= mx; i++) {
		if (isprime[i]) {
			primes.push_back(i);

			if (i * i <= mx) {
				for (ll j = i * i; j <= mx; j += i) {
					isprime[j] = 0;
				}
			}
		}
	}

	vector<vector<int>> adj(n);
	vector<int> prev(n, -1);
	vector<vector<int>> padj(primes.size());
	vector<int> pprev(primes.size(), -1);

	for (int i = 0; i < n; i++) {
		int cur = a[i];

		for (int j = 0; j < primes.size(); j++) {
			if (cur == 1) {
				break;
			}

			if (isprime[cur]) {
				int pos = lower_bound(primes.begin(), primes.end(), cur) - primes.begin();
				adj[i].push_back(pos);
				padj[pos].push_back(i);

				break;
			}

			if (cur % primes[j] == 0) {
				adj[i].push_back(j);
				padj[j].push_back(i);

				while (cur % primes[j] == 0) {
					cur /= primes[j];
				}
			}
		}
	}

	queue<array<int, 2>> bfs;
	bfs.push({t, 1});

	while (!bfs.empty()) {
		auto cur = bfs.front();
		bfs.pop();

		if (cur[0] == s && cur[1]) {
			break;
		}

		if (cur[1]) {
			for (auto nxt : adj[cur[0]]) {
				if (pprev[nxt] == -1) {
					pprev[nxt] = cur[0];
					bfs.push({nxt, 0});
				}
			}
		}
		else {
			for (auto nxt : padj[cur[0]]) {
				if (prev[nxt] == -1) {
					prev[nxt] = pprev[cur[0]];
					bfs.push({nxt, 1});
				}
			}
		}
	}

	if (prev[s] == -1) {
		cout << -1 << endl;
	}
	else {
		vector<int> ans;

		while (s != t) {
			ans.push_back(s);
			s = prev[s];
		}

		ans.push_back(t);

		cout << ans.size() << '\n';
		for (auto sp : ans) {
			cout << sp + 1 << " ";
		}

		cout << '\n';
	}
}
