#include <bits/stdc++.h>

using namespace std;

int main() {
	int t;
	cin >> t;

	while (t--) {
		int n, m;
		cin >> n >> m;
		vector<string> grid(n);
		vector<vector<int>> spruce(n, vector<int>(m));

		for (string& s : grid) {
			cin >> s;
		}

		auto sp = [&spruce, &m, &n](int x, int y) {
			if (x < 0 || x >= n || y < 0 || y >= m) {
				return 0;
			}

			return spruce[x][y];
		};
		
		long long ans = 0;

		for (int i = n - 1; i >= 0; i--) {
			for (int j = 0; j < m; j++)  {
				if (grid[i][j] == '*') {
					spruce[i][j] = 1;
					spruce[i][j] += min({sp(i + 1, j - 1), sp(i + 1, j), sp(i + 1, j + 1)});
					ans += spruce[i][j];
				}
			}
		}

		cout << ans << endl;
	}
}
