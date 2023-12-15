#include <bits/stdc++.h>
#include <pthread.h>

using namespace std;

int main() {
	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;

		vector<int> a(n), b(n);

		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}

		for (int i = 0; i < n; i++) {
			cin >> b[i];
		}

		vector<vector<pair<int, int>>> ranges(n + 1);

		bool success = 1;

		for (int i = 1; i <= n; i++) {
			int rstart = -1;
			bool ifound = 0;
			for (int j = 0; j < n; j++) {
				if (b[j] == i) {
					ifound = 1;
				}

				if (rstart == -1 && b[j] >= i) {
					rstart = j;
				}

				if (b[j] < i && rstart != -1) {
					if (ifound) {
						ranges[i].push_back({rstart, j - 1});
						cout << i << " " << rstart << " " << j - 1 << endl;
					}
					ifound = 0;
					rstart = -1;
				}
			}

			if (rstart != -1 && ifound) {
				ranges[i].push_back({rstart, n - 1});
				cout << i << " " << rstart << " " << n - 1 << endl;
			}

			for (int j = 0; j < ranges[i].size(); j++) {
				bool found = 0;
				for (int k = ranges[i][j].first; k <= ranges[i][j].second; k++) {
					if (a[k] == i) {
						found = 1;
						break;
					}
				}

				if (!found) {
					success = 0;
					break;
				}
			}

			if (!success) {
				break;
			}
		}


		cout << (success ? "YES" : "NO") << endl;
		cout << "----------------" << endl;
	}
}
