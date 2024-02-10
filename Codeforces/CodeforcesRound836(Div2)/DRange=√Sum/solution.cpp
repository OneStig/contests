#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main() {
	int t;
	cin >> t;

	while (t--) {
		ll n;
		cin >> n;

		if (n % 2 != 0) {
			// 2 3 4
		}
		else {
			ll reduce = (n + 1) * (n - 2) / 2 / n;
			ll first = n - 1 - reduce;

			cout << first;
			
			for (int i = 1; i < n; i++) {
				ll cur = n + i - reduce;
				cout << " " << cur;
			}
		}


		cout << endl;
	}
}
