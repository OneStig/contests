#include <bits/stdc++.h>

using namespace std;

using pokeset = unsigned short;

int main() {
	int n;
	cin >> n;
	
	map<string, int> pname;
	vector<array<int, 3>> poke; // x, y, id

	poke.push_back({0, 0, 0});
	pname["start"] = 0;

	for (int i = 0; i < n; i++) {
		int x, y;
		string name;
		cin >> x >> y >> name;

		if (pname.find(name) == pname.end()) {
			pname[name] = pname.size();
		}

		poke.push_back({x, y, pname[name]});
	}

	map<tuple<pokeset, int>, int> dp;
	dp[{1, 0}] = 0;

	while (1) {
		map<tuple<pokeset, int>, int> nextdp;

		for (auto it = dp.begin(); it != dp.end(); it++) {
			auto [cs, last] = (*it).first;

			int fromx = poke[last][0], fromy = poke[last][1];

			for (int i = 1; i < n + 1; i++) {
				int ptype = poke[i][2];

				if ((cs & (pokeset)(1 << ptype)) == 0) {
					pokeset ns = cs + (pokeset)(1 << ptype);
					int dist = abs(fromx - poke[i][0]) + abs(fromy - poke[i][1]);
					tuple<pokeset, int> nthing = {ns, i};

					if (nextdp.find(nthing) != nextdp.end()) {
						nextdp[nthing] = min(nextdp[nthing], (*it).second + dist);
					}
					else {
						nextdp[nthing] = (*it).second + dist;
					}
				}
			}
		}

		if (nextdp.size() == 0) {
			break;
		}

		dp = nextdp;
	}

	int ans = INT_MAX;

	for (auto it = dp.begin(); it != dp.end(); it++) {
		auto [cs, last] = (*it).first;
		ans = min(ans, (*it).second + abs(poke[last][0]) + abs(poke[last][1]));
	}

	cout << ans << "\n";
}
