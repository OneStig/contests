#include <bits/stdc++.h>

using namespace std;

#define ll long long

const ll PRICE = 1e12;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;

	while (t--) {
		string s;
		cin >> s;
		int n = s.size();

		if (n == 1) {
			cout << "0\n";
			continue;
		}

		int foundz = 0, oneleft = 0;

		for (int i = 0; i < s.size(); i++) {
			oneleft += s[i] - '0';
		}

		ll ans = LLONG_MAX;
		for (int i = 0; i + 1 < n; i++) {
			foundz += s[i] == '0';
			oneleft -= s[i] == '1';

			int badpos = n - foundz - oneleft - (s[i] == '1') - (s[i + 1] == '0');
			ll curans = badpos * (PRICE + 1);

			if (s[i] == '1' && s[i + 1] == '0') {
				curans += PRICE;
			}

			ans = min(ans, curans);
		}

		cout << ans << "\n";
	}
}
