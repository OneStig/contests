#include <bits/stdc++.h>

using namespace std;

#define ll long long
const int MOD = 1e9 + 7;

template <class T> struct SegTree {
	const T DEFAULT = 1;

	vector<T> segtree;
	int tree_n;

	SegTree(int tree_n) : tree_n(tree_n), segtree(tree_n * 2, DEFAULT) {}

	void set(int ind, T val) {
		ind += tree_n;
		segtree[ind] = val;

		while (ind > 1) {
			segtree[ind / 2] = (segtree[ind] * segtree[ind ^ 1]) % MOD;
			ind /= 2;
		}
	}

	T sum(int start, int end) {
		T sum = DEFAULT;
		for (start += tree_n, end += tree_n; start < end; start /= 2, end /= 2) {
			if (start % 2 == 1) {
				sum *= segtree[start++];
				sum %= MOD;
			}

			if (end % 2 == 1) {
				sum *= segtree[--end];
				sum %= MOD;
			}
		}
		return sum;
	}
};

int main() {
	int t;
	cin >> t;

	while (t--) {
		int n, m;
		cin >> n >> m;
		map<ll, ll> freq;

		for (int i = 0; i < n; i++) {
			ll a;
			cin >> a;

			freq[a]++;
		}

		n = freq.size();

		vector<ll> b(n);
		SegTree<ll> st(n);

		int k = 0;
		for (auto x : freq) {
			b[k] = x.first;
			st.set(k, x.second);
			k++;
		}

		ll ans = 0;
		for (int i = 0; i <= n - m; i++) {
			if (b[i + m - 1] - b[i] == m - 1) {
				ans += st.sum(i, i + m);
				//cout << i << " " << i + m - 1 << " " << st.sum(i, i + m) << '\n';
				//cout << b[i] << " " << ans << '\n';
				ans %= MOD;
			}
		}
		//debug(b);

		cout << ans << '\n';
	}
}
