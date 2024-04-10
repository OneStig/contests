#include <bits/stdc++.h>
//#include <bits/debug.h>

using namespace std;

#define ld long double

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int s, t;
	cin >> s;

	vector<array<int, 4>> l(s);

	for (auto& x : l) {
		cin >> x[0] >> x[1] >> x[2] >> x[3];
	}

	cin >> t;

	vector<array<int, 4>> p(t);
	vector<bool> ans(t);

	for (auto& x : p) {
		cin >> x[0] >> x[1] >> x[2] >> x[3];
	}

	for (int i = 0; i < s; i++) {
		bool vert = l[i][0] == l[i][2];

		ld slope;
		if (!vert) {
			slope = (ld)(l[i][1] - l[i][3]) / (ld)(l[i][0] - l[i][2]);
		}

		for (int j = 0; j < t; j++) {
			if (vert) {
				if ((p[j][0] < l[i][0]) != (p[j][2] < l[i][0])) {
					ans[j] = !ans[j];
				}
			}
			else {
				bool first = slope * (p[j][0] - l[i][0]) + l[i][1] > p[j][1];
				bool second = slope * (p[j][2] - l[i][0]) + l[i][1] > p[j][3];

				if (first != second) {
					ans[j] = !ans[j];
				}
			}
		}
	}

	for (bool b : ans) {
		cout << (b ? "different" : "same") << "\n";
	}
}
