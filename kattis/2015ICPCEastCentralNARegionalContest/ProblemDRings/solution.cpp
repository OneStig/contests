#include <bits/stdc++.h>

using namespace std;

void fmt(int x, int t) {
	if (x == 0) {
		if (t < 10) {
			cout << "..";
		}
		else {
			cout << "...";
		}
	}
	else if (t < 10) {
		cout << "." << x;
	}
	else {
		if (x < 10) {
			cout << ".." << x;
		}
		else {
			cout << "." << x;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	int n, m;
	cin >> n >> m;

	vector<string> grid(n + 2);
	grid[0] = string(m + 2, '.');
	grid[n + 1] = grid[0];

	vector<vector<int>> ans(n + 2, vector<int>(m + 2, -1));
	ans[0] = vector<int>(m + 2, 0);
	ans[n + 1] = ans[0];

	vector<array<int, 2>> tmark;

	for (int i = 1; i <= n; i++) {
		string tmp;
		cin >> tmp;

		grid[i] = "." + tmp + ".";

		for (int j = 0; j < m + 2; j++) {
			if (grid[i][j] == '.') {
				ans[i][j] = 0;
			}
		}
	}


	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (grid[i][j] == 'T' &&
				(grid[i - 1][j] == '.' ||
				 grid[i + 1][j] == '.' ||
				 grid[i][j - 1] == '.' ||
				 grid[i][j + 1] == '.')) {
				tmark.push_back({i, j});
				ans[i][j] = 1;
			}
		}
	}

	int l = 1;
	while (l <= max(n, m)) {
		if (tmark.size() == 0) {
			break;
		}

		l++;

		vector<array<int, 2>> nextmark;

		for (int i = 0; i < tmark.size(); i++) {
			auto cur = tmark[i];

			if (ans[cur[0] + 1][cur[1]] == -1) {
				nextmark.push_back({cur[0] + 1, cur[1]});
				ans[cur[0] + 1][cur[1]] = l;
			}

			if (ans[cur[0] - 1][cur[1]] == -1) {
				nextmark.push_back({cur[0] - 1, cur[1]});
				ans[cur[0] - 1][cur[1]] = l;
			}

			if (ans[cur[0]][cur[1] + 1] == -1) {
				nextmark.push_back({cur[0], cur[1] + 1});
				ans[cur[0]][cur[1] + 1] = l;
			}

			if (ans[cur[0]][cur[1] - 1] == -1) {
				nextmark.push_back({cur[0], cur[1] - 1});
				ans[cur[0]][cur[1] - 1] = l;
			}
		}

		tmark = nextmark;
	}

	l--;
	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			fmt(ans[i][j], l);
		}
		cout << '\n';
	}
}
