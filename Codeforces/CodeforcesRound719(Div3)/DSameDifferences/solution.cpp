#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main() {
	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;

		vector<int> a(n);

		for (int& i : a) {
			cin >> i;
		}

		map<int, ll> diff;
		ll ans = 0;

		for (int i = 0; i < n; i++) {
			ans += diff[a[i] - i];
			diff[a[i] - i]++;
		}

		cout << ans << endl;
	}
}
