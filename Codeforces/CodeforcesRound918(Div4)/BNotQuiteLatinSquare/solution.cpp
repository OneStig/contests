#include <bits/stdc++.h>

using namespace std;

int main() {
	int t;
	cin >> t;

	while (t--) {
		char ans = 'A';
		for (int i = 0; i < 3; i++) {
			string s;
			cin >> s;

			int sum = s[0] + s[1] + s[2];

			if (sum != (int)('A' + 'B' + 'C')) {
				ans = 'A' + 'B' + 'C' - (sum - '?');
			}
		}

		cout << ans << endl;
	}
}
