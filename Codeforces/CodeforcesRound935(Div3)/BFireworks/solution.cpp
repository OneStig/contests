#include <bits/stdc++.h>

#define ll long long

using namespace std;

int main() {
	int t;
	cin >> t;

	while (t--) {
		ll a, b, m;
		cin >> a >> b >> m;

		cout << m / a + m / b + 2 << '\n';
	}
}
