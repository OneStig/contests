#include <bits/stdc++.h>

using namespace std;

int main() {
	int t;
	cin >> t;

	while (t--) {
		int n, x;
		cin >> n >> x;

		vector<int> a(n), b(n);
		vector<pair<int, int>> ai(n);

		for (int i = 0; i < n; i++) {
			cin >> a[i];
			ai[i] = {a[i], i};
		}

		for (int i = 0; i < n; i++) {
			cin >> b[i];
		}

		vector<int> ans(n);
		sort(b.begin(), b.end());
		sort(ai.rbegin(), ai.rend());

		bool fail = 0;

		int back = x - 1;
		for (int i = 0; i < x; i++, back--) {
			auto curb = b[back];
			auto cura = ai[i];

			if (curb >= cura.first) {
				fail = 1;
				break;
			}

			ans[cura.second] = curb;
		}

		if (fail) {
			cout << "NO" << endl;
			continue;
		}

		back = n - 1;
		for (int i = x; i < n; i++, back--) {
			auto cura = ai[i];
			auto curb = b[back];

			if (cura.first > curb) {
				fail = 1;
				break;
			}

			ans[cura.second] = curb;
		}


		if (fail) {
			cout << "NO" << endl;
			continue;
		}

		cout << "YES" << endl;

		for (int i = 0; i < n; i++) {
			if (i != 0) {
				cout << " ";
			}

			cout << ans[i];
		}

		cout << endl;
	}
}
