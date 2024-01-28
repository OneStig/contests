#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	cin >> n;

	vector<string> grid(n);

	for (auto& s : grid) {
		cin >> s;
	}

	auto check = [&grid](int x, int y) {
		bool cross = grid[x][y] != '#';
		grid[x][y] = '.';

		return cross;
	};

	bool fail = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (grid[i][j] == '#') {
				if (j == 0 || j == n - 1 || i >= n - 2 ||
					check(i + 1, j) ||
					check(i + 1, j - 1) ||
					check(i + 1, j + 1) ||
					check(i + 2, j)) {
					fail = 1;
					break;
				}
			}
		}

		if (fail) {
			break;
		}
	}

	cout << (fail ? "NO" : "YES") << endl;
}
