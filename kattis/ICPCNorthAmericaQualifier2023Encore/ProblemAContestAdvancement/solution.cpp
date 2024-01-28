#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, k, c;
	cin >> n >> k >> c;

	map<int, int> sc;

	vector<array<int, 2>> teams(n);
	vector<bool> going(n);

	for (int i = 0; i < n; i++) {
		cin >> teams[i][0] >> teams[i][1];

		if (k != 0 && sc[teams[i][1]] < c) {
			sc[teams[i][1]]++;
			going[i] = 1;
			k--;
		}
	}

	for (int i = 0; i < n; i++) {
		if (k == 0) {
			break;
		}

		if (!going[i]) {
			going[i] = 1;
			k--;
		}
	}


	for (int i = 0; i < n; i++) {
		if (going[i]) {
			cout << teams[i][0] << endl;
		}
	}
}
