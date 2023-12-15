#include <bits/stdc++.h>
#include <unordered_set>

using namespace std;

int main() {
	int t;
	cin >> t;

	while (t--) {
		int a, b, xk, yk, xq, yq;
		cin >> a >> b >> xk >> yk >> xq >> yq;

		pair<int, int> os[] = {
			{a, b},
			{b, a},
			{-a, b},
			{-b, a},
			{a, -b},
			{b, -a},
			{-a, -b},
			{-b, -a},
		};

		vector<pair<int, int>> spots;

		for (int i = 0; i < 8; i++) {
			spots.push_back({xk + os[i].first, yk + os[i].second});
		}

		vector<pair<int, int>> qspots;

		for (int i = 0; i < 8; i++) {
			pair<int, int> nq = {xq + os[i].first, yq + os[i].second};

			if (find(qspots.begin(), qspots.end(), nq) == qspots.end()) {
				qspots.push_back(nq);
			}
		}

		int ans = 0;
		for (int i = 0; i < qspots.size(); i++) {
			pair<int, int> x = qspots[i];

			if (find(spots.begin(), spots.end(), x) != spots.end() && !(x.first == xk && x.second == yk)) {
				ans++;
			}
		}

		cout << ans << endl;
	}
}

