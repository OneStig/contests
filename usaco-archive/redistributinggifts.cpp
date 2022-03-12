#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 20;
uint64_t ans[1 << MAX_N];
uint64_t dp[1 << MAX_N][MAX_N];
int adj[MAX_N];
int N;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> N;
	assert(N <= MAX_N);
	for (int i = 0; i < N; ++i) {
		vector<int> pref(N);
		for (int &g : pref)
			cin >> g;
		for (int &g : pref) {
			--g;
			adj[i] |= 1 << g;
			if (g == i)
				break;
		}
	}
	ans[0] = 1;
	for (int k = 0; k < N; ++k) // start a cycle
		dp[1 << k][k] = 1;
	for (int i = 0; i < N; ++i) {
		for (int mask = 1 << i; mask < 1 << (i + 1); ++mask) {
			for (int last = 0; last <= i; ++last)
				if (mask & (1 << last)) {
					const uint64_t val = dp[mask][last];
					for (int k = 0; k < i; ++k) // case 1, extend the cycle
						if (!(mask & (1 << k)))
							if (adj[last] & (1 << k))
								dp[mask ^ (1 << k)][k] += val;
					if (adj[last] & (1 << i)) // case 2, complete the cycle
						ans[mask] += val;
				}
			for (int k = i + 1; k < N; ++k) // start a new cycle
				dp[mask ^ (1 << k)][k] += ans[mask];
		}
	}
	int Q;
	cin >> Q;
	while (Q--) {
		string breeds;
		cin >> breeds;
		int g = 0, h = 0;
		for (int i = 0; i < N; ++i) {
			if (breeds[i] == 'G')
				g ^= 1 << i;
			else
				h ^= 1 << i;
		}
		cout << ans[g] * ans[h] << "\n";
	}
}