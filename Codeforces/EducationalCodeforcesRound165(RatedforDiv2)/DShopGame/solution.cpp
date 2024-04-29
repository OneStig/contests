#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main() {
	int t;
	cin >> t;

	while (t--) {
		ll n, k;
		cin >> n >> k;

		vector<array<ll, 2>> items(n);
		ll zans = 0;

		for (int i = 0; i < n; i++) {
			cin >> items[i][1];
		}
		
		for (int i = 0; i < n; i++) {
			cin >> items[i][0];
			items[i][0] *= -1;
		}

		sort(items.begin(), items.end());


		vector<ll> suffix(n + 1);
		suffix[n] = 0;

		for (int i = n - 1; i >= 0; i--) {
			suffix[i] = suffix[i + 1] + max(-items[i][0] - items[i][1], (ll)0);
		}

		if (k == 0) {
			cout << suffix[0] << '\n';
			continue;
		}

		ll ans = 0;
		ll curloss = 0;
		priority_queue<ll> aval;
		for (int i = 0; i < k; i++) {
			curloss -= items[i][1];
			aval.push(items[i][1]);
		}

		for (int i = k; i < n; i++) {
			ans = max(ans, curloss + suffix[i]);

			curloss += aval.top();
			ll top = min(aval.top(), items[i][1]);
			curloss -= top;
			aval.pop();
			aval.push(top);
		}

		cout << ans << '\n';
	}
	
}
