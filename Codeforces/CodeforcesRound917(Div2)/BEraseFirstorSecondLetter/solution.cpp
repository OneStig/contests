#include <bits/stdc++.h>

using namespace std;

int main() {
	int t;
	cin >> t;

	while (t--) {
		int n;
		string s;
		cin >> n >> s;

		long long ans = 0;
		unordered_set<char> c;

		for (int i = 0; i < n; i++) {
			c.insert(s[i]);
			ans += c.size();
		}

		cout << ans << endl;
	}
}
