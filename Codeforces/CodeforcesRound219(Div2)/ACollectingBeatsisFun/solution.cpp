#include <bits/stdc++.h>

using namespace std;

int main() {
	int k;
	cin >> k;
	k *= 2;

	vector<int> c(9);

	bool fail = 0;
	for (int i = 0; i < 4; i++) {
		string s;
		cin >> s;

		for (int j = 0; j < 4; j++) {
			if (s[j] != '.') {
				c[s[j] - '1']++;

				if (c[s[j] - '1'] > k) {
					fail = 1;
				}
			}
		}
	}

	cout << (fail ? "NO" : "YES") << endl;
}
