#include <bits/stdc++.h>

using namespace std;

int main() {
	int t;
	cin >> t;

	while (t--) {
		int n;
		string s;
		cin >> n >> s;

		vector<int> a(26, 0);

		for (int i = 0; i < n; i++) {
			a[s[i] - 'A']++;
		}

		int ans = 0;
		for (int i = 0; i < 26; i++) {
			ans += a[i] > i;
		}

		cout << ans << endl;
	}
}
