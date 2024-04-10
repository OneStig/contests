#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main() {
	int t;
	cin >> t;

	while (t--) {
		ll n, k;
		cin >> n >> k;

		ll c = 1;
		ll layer = (n + 1) / 2;
		ll remain = n / 2;

		while (k > layer) {
			k -= layer;
			layer = (remain + 1) / 2;
			remain = remain / 2;
			c *= 2;
		}

		cout << (2 * k - 1) * c << "\n";
	}
}

// 1, 3, 5, 7, 9 ...
// 2, 6, 10, 14 ...
// 3, 9, 

// 1: 1, 3, 5, 7, 9
// 2: 2, 6, 10, 14
// 4: 4, 
