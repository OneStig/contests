#include <bits/stdc++.h>

using namespace std;

typedef int uci;
#define int long long
#define sz(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()

uci main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

	int k, n;
	cin >> k >> n;

	set<string> cands;

	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;

		set<string> curcands;
		set<string> cur;
		cur.insert("");

		for (char c : s) {
			set<string> ncur;
			for (string prev : cur) {
				prev += c;
				if (sz(prev) == k) {
					curcands.insert(prev);
				}
				else if (sz(prev) < k) {
					ncur.insert(prev);
				}
			}

			for (string nc : ncur) {
				cur.insert(nc);
			}
		}

		if (i == 0) {
			cands = curcands;
		}
		else {
			if (sz(curcands) < sz(cands)) {
				swap(cands, curcands);
			}

			set<string> nextcands;
			for (string c : cands) {
				if (curcands.find(c) != curcands.end()) {
					nextcands.insert(c);
				}
			}

			cands = nextcands;
		}
	}

	cout << sz(cands) << '\n';
	for (string x : cands) {
		cout << x << '\n';
	}
}
