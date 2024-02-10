// WICS - ACM
// C++ Forest Queries
// https://cses.fi/problemset/task/1652

#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, q;
	cin >> n >> q;

	vector<vector<char>> forest(n + 1, vector<char>(n + 1));
	vector<vector<long long>> prefix(n + 1, vector<long long>(n + 1));

	for (int r = 1; r <= n; r++) {
		for (int c = 1; c <= n; c++) {
			cin >> forest[r][c];

			prefix[r][c] = (forest[r][c] == '*') + prefix[r - 1][c] + prefix[r][c - 1] - prefix[r - 1][c - 1];
		}
	}

	while (q--) {
		int y1, x1, y2, x2;
		cin >> y1 >> x1 >> y2 >> x2;

		cout << prefix[y2][x2] - prefix[y1 - 1][x2] - prefix[y2][x1 - 1] + prefix[y1 - 1][x1 - 1] << endl;
	}
}
