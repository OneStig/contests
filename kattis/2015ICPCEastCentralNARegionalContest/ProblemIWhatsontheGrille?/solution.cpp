#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	string msg;
	string grille;

	vector<array<int, 2>> holes;

	for (int i = 0; i < n; i++)	{
		cin >> grille;

		for (int j = 0; j < n; j++) {
			if (grille[j] == '.') {
				holes.push_back({i, j});
			}
		}
	}

	cin >> msg;

	if (n % 2 == 1 || holes.size() != n * n / 4) {
		cout << "invalid grille\n";
		return 0;
	}

	vector<vector<char>> decrypt(n, vector<char>(n, '#'));

	int pos = 0;
	for (int r = 0; r < 4; r++) {
		for (int i = 0; i < holes.size(); i++) {
			decrypt[holes[i][0]][holes[i][1]] = msg[pos++];
		}

		if (r < 3) {
			vector<array<int, 2>> new_holes;

			for (int i = 0; i < holes.size(); i++) {
				new_holes.push_back({holes[i][1], n - holes[i][0] - 1});
			}

			holes = new_holes;
			sort(holes.begin(), holes.end());
		}
	}

	string ans = "";

	bool fail = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (decrypt[i][j] == '#') {
				fail = 1;
				break;
			}

			ans += decrypt[i][j];
		}

		if (fail) {
			break;
		}
	}

	if (fail) {
		cout << "invalid grille\n";
	}
	else {
		cout << ans << endl;
	}
}
