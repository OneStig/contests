#include <bits/stdc++.h>

using namespace std;

int main() {
	int v;
	cin >> v;

	vector<int> dig(10);

	int mindig = INT_MAX;
	int which = 0;

	for (int i = 1; i <= 9; i++) {
		cin >> dig[i];

		if (dig[i] < mindig) {
			mindig = dig[i];
			which = i;
		}
	}

	int total = v / mindig;

	if (total == 0) {
		cout << "-1\n";
		return 0;
	}

	v -= total * mindig;

	for (int i = 1; i <= 9; i++) {
		dig[i] -= mindig;
	}

	for (int i = 0; i < total; i++) {
		for (int d = 9; d >= 1; d--) {
			if (v >= dig[d]) {
				cout << d;
				v -= dig[d];
				break;
			}
		}
	}

	cout << "\n";
}

