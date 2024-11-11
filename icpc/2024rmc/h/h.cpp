#include <bits/stdc++.h>

using namespace std;

typedef int uci;
#define int unsigned long long
#define sz(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()

uci main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

	int n, c;
	cin >> n >> c;

	vector<int> a(n);
	for(int i = 0; i < n; ++i) {
		cin >> a[i];
	}

	sort(all(a));
	int minim = a[0];
	int cnt = a[0];
	int power = 2;
	while((minim + power - 1) / power != 1) {
		cnt += ((minim + power - 1) / power) ;
		power *= 2;
	}

	if(cnt <= c) {
		cout << "Yes\n";
		return 0;
	}

	else {
		// knapckack
		vector<int> dp(c + 1, 0);
		dp[0] = 1;
		for(auto x : a) {
			if(x <= c) {
				dp[x] = 1;
			}
		}

		if(dp[c] == 1) {
			cout << "Yes\n";
			return 0;
		}

		for(int bit = 1; bit < 63; ++bit) {
			int power = (1ll << bit);
			vector<int> ndp(c + 1, 0);
			for(int i = 0; i < n; ++i) {
				int element = (a[i] + power - 1) / power;
				for(int j = 1; j <= c; ++j) {
					if(dp[j] == 1 && j + element <= c) {
						ndp[j + element] = 1;
					}
				}
			}

			swap(dp, ndp);

			if(dp[c] == 1) {
				cout << "Yes\n";
				return 0;
			}
		}

		cout << "No\n";
	}
}
