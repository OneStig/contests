#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
#include <bits/debug.h>
#endif

using namespace std;

int main() {
	int n;
	cin >> n;

	vector<int> a(n);

	int mx = INT_MIN;
	for (int& i : a) {
		cin >> i;
		mx = max(mx, i);
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

	for (int i = 1; i <= mx; i++) {
		if (isprime[i]) {
			primes.push_back(i);

			for (int j = i * i; j <= mx; j += i) {
				isprime[j] = 0;
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
	prev[t] = -2;

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

	if (prev[1] == -1) {
		cout << -1 << endl;
	}
	else {
		vector<int> ans;

		ans.push_back(s);

		while (prev[s] != -2) {
			s = prev[s];
			ans.push_back(s);
		}

		cout << ans.size() << endl;
		for (auto sp : ans) {
			cout << sp + 1 << " ";
		}

		cout << endl;
	}
}
