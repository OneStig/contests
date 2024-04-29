#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main() {
	int t;
	cin >> t;

	while (t--) {
		string s;
		cin >> s;

		ll f = -1;
		ll ans = 0;

		for (ll i = 0; i < s.size(); i++) {
			if (s[i] == '1') {
				if (f == -1) {
					f = i;
				}
			}
			else {
				if (f != -1) {
					ans += i - f + 1;
					f++;
				}
			}
		}

		cout << ans << '\n';
	}
}
