#include <bits/stdc++.h>

using namespace std;

int main() {
	int t;
	cin >> t;

	while (t--) {
		int a, b, c;
		cin >> a >> b >> c;

		if (b % 3 != 0 && 3 - (b % 3) > c) {
			cout << -1 << '\n';
			continue;
		}

		cout << a + (b + c) / 3 + ((b + c) % 3 ? 1 : 0) << '\n';
	}
}
