#include <bits/stdc++.h>

using namespace std;

vector<array<int, 20>> lift;

int main() {
	int n, q;
	cin >> n >> q;

	lift.resize(n + 1);

	for (int i = 1; i <= n; i++) {
		cin >> lift[i][0];
	}

	for (int b = 1; b < 20; b++) {
		for (int i = 1; i <= n; i++) {
			lift[i][b] = lift[lift[i][b - 1]][b - 1];
		}
	}

	while (q--) {
		int x, k;
		cin >> x >> k;

		for (int i = 0; k; i++) {
			if (k & 1) {
				x = lift[x][i];
			}

			k >>= 1;
		}

		cout << x << '\n';
	}
}
