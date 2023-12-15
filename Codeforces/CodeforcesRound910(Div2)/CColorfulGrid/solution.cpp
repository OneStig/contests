#include <bits/stdc++.h>

using namespace std;

int main() {
	int t;
	cin >> t;
	
	while (t--) {
		int n, m, k;
		cin >> n >> m >> k;

		if (k < (m - 2 + n) || k % 2 != (n + m) % 2) {
			cout << "NO" << endl;
			continue;
		}

		vector<vector<char>> horiz(n);
		vector<vector<char>> vert(n - 1);
		
		for (int i = 0; i < n; i++) {
			horiz[i].resize(m - 1, 'R');
		}

		for (int i = 0; i < n - 1; i++) {
			vert[i].resize(m, 'B');
		}

		for (int i = 0; i < m - 1; i++) {
			horiz[0][i] = (i % 2 ? 'B' : 'R');
		}

		for (int i = 0; i < n - 1; i++) {
			vert[i][m - 1] = (i % 2 != n % 2 ? 'B' : 'R');
		}

		horiz[n - 1][m - 2] = (n + m) % 2 ? 'R' : 'B';
		horiz[n - 2][m - 2] = (n + m) % 2 ? 'R' : 'B';
		vert[n - 2][m - 2] = (n + m) % 2 ? 'B' : 'R';

		cout << "YES" << endl;
	
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < horiz[i].size(); j++) {
				if (j != 0) {
					cout << " ";
				}

				cout << horiz[i][j];
			}
			cout << endl;
		}

		for (int i = 0; i < n - 1; i++) {
			for (int j = 0; j < vert[i].size(); j++) {
				if (j != 0) {
					cout << " ";
				}

				cout << vert[i][j];
			}
			cout << endl;
		}
	}
}
