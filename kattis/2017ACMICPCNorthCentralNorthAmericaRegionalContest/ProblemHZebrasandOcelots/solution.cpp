#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main() {
	int n;
	cin >> n;

	ll ans = 0;

	while (n--) {
		char x;
		cin >> x;

		ans = ans << 1;
		ans += x == 'O';
	}

	cout << ans << '\n';
}
