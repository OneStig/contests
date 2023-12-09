#include <bits/stdc++.h>

using namespace std;

int main() {
	int t;
	cin >> t;

	while (t--) {
		int n;
		string s;
		cin >> n >> s;

		bool ans = 0;

		for (int i = 0; i < n; i++) {
			if (s[i] == '0') {
				ans = 1;
				break;
			}
		}

		cout << (ans ? "YES" : "NO") << endl;
	}
}
