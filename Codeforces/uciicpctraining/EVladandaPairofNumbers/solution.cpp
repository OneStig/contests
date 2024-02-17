#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main() {
	int t;
	cin >> t;

	while (t--) {
		ll x;
		cin >> x;
		
		ll a = x / 2;
		ll b = 2 * x - a;

		if ((a ^ b) == x) {
			cout << a << " " << b << "\n";
		}
		else {
			cout << -1 << "\n";
		}
	}
}

// 6 -> 110, 011, 
