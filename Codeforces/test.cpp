#inlcude <bits/stdc++.h>

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
			{-a, b},
			{-b, a},
		};

		unordered_set<pair<int, int>> spots;

		for (int i = 0; i < 8; i++) {
			spots.insert({xk + os[i].first, yk + os[i].second});
		}

		unordered_set<pair<int, int>> qspots;

		for (int i = 0; i < 8; i++) {
			spots.insert({xq + os[i].first, yq + os[i].second});
		}

		int ans = 0;
		for (auto it = qspots.begin(); it != qspots.end(); q++) {
			pair<int, int> x = *it;

			if (spots.find(x) != spots.end() && !(x.first == xk && x.second == yk)) {
				ans++;
			}
		}
	}
}
