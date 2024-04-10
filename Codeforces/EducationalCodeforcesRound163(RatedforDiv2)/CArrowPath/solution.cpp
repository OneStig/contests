#include <bits/stdc++.h>
#include <bits/debug.h>

using namespace std;

int dfs(int x, int y, vector<array<int, 2>>& ans, vector<array<char, 2>>& grid) {
	if (ans[x][y] != -1) {
		return ans[x][y];
	}

	ans[x][y] = 0;

	if (y == 0) {
		ans[x][y] = ans[x][y] || dfs(x + (grid[x][1] == '>' ? 1 : -1), 1, ans, grid) == 1;
	}

	if (y == 0) {
		ans[x][y] = ans[x][y] || dfs(x + (grid[x][0] == '>' ? 1 : -1), 0, ans, grid) == 1;
	}

	if (x > 0) {
		ans[x][y] = ans[x][y] || dfs(x - 1 + (grid[x - 1][y] == '>' ? 1 : -1), y, ans, grid) == 1;
	}

	if (x < ans.size() - 1) {
		ans[x][y] = ans[x][y] || dfs(x + 1 + (grid[x + 1][y] == '>' ? 1 : -1), y, ans, grid) == 1;
	}

	return ans[x][y];
}

int main() {
	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;

		vector<array<char, 2>> grid(n);

		for (int i = 0; i < n; i++) {
			cin >> grid[i][0];
		}

		for (int i = 0; i < n; i++) {
			cin >> grid[i][1];
		}

		vector<array<int, 2>> ans(n, {-1, -1});
		ans[n - 1][1] = 1;
		ans[n - 1][0] = 1;
		ans[n - 2][1] = 1;

		debug(ans);
		cout << (dfs(0, 0, ans, grid) ? "YES" : "NO") << '\n';
		debug(ans);
	}
}
