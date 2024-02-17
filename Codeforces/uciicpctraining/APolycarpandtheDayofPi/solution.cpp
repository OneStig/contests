#include <bits/stdc++.h>

using namespace std;

const string pi = "3141592653589793238462643383279";

int main() {
	int t;
	cin >> t;

	while (t--) {
		string s;
		cin >> s;

		int ans = 0;

		for (int i = 0; i < s.size(); i++) {
			if (s[i] != pi[i]) {
				break;
			}

			ans++;
		}

		cout << ans << "\n";
	}
}
