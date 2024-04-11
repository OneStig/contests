#include <bits/stdc++.h>

using namespace std;

int main() {
	int t;
	cin >> t;

	while (t--) {
		vector<int> f(5);
		cin >> f[1] >> f[2] >> f[3] >> f[4];
		int ans = 0;

		while (f[1] + f[2] + f[3] + f[4]) {
			ans += (f[4] % 2 == 0 && (f[2] + f[3]) % 2 == 0 && (f[1] + f[3]) % 2 == 0);
		}

		cout << ans << '\n';
	}
}

// bob wins if
// f[1] + f[3] even
// f[2] + f[3] even
// f[4] even

// 1 001
// 2 010
// 3 011
// 4 100
