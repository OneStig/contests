#include <bits/stdc++.h>

using namespace std;

int main() {
	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;
		string s;
		cin >> s;

		int first = -1, last = -1;

		for (int i = 0; i < n; i++) {
			if (s[i] == 'B') {
				if (first == -1) {
					first = i;
				}

				last = i;
			}
		}

		if (first == -1) {
			cout << 0 << endl;
			continue;
		}

		cout << last - first + 1 << endl;
	}
}
