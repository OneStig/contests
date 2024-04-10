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

		int sum = 0;

		vector<int> pos;
		for (int i = 0; i < n; i++) {
			sum += s[i] - '0';

			if (s[i] == '1') {
				pos.push_back(i);
			}
		}

		if (sum % 2 || (sum == 2 && pos[1] - pos[0] == 1)) {
			cout << "NO\n";
		}
		else {
			cout << "YES\n";
		}
	}
}
