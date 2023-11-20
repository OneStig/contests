#include <bits/stdc++.h>

using namespace std;

int main() {
	int t;
	cin >> t;

	while (t--) {
		int n, k;
		cin >> n >> k;
		string s;
		cin >> s;

		int b = 0;
		for (int i = 0; i < n; i++) {
			b += s[i] == 'B';
		}

		if (b == k) {
			cout << 0 << endl;
			continue;
		}

		cout << 1 << endl;

		int cnt = 0;
		if (b > k) {
			for (int i = 0; i < n; i++) {
				cnt += s[i] == 'B';

				if (cnt == b - k) {
					cout << i + 1 << " A";
					break;
				}
			}
		}
		else {
			for (int i = 0; i < n; i++) {
				cnt += s[i] == 'A';

				if (cnt == k - b) {
					cout << i + 1 << " B";
					break;
				}
			}
		}

		cout << endl;
	}
}
