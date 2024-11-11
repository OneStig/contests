#include <bits/stdc++.h>

using namespace std;

typedef int uci;
#define int long long
#define sz(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()

uci main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	int n,g,d,m;
	cin >> n >> g >> d >> m;
	set<int> sandwich;
	for (int i = 0; i < n ;i++) {
		int k;
		cin >>  k;
		sandwich.insert(k);
	}
	vector<set<int>> gs;
	for (int i = 0; i < g; i++) {
		int k;
		cin >> k;
		set<int> gn;
		for (int j = 0; j < k; j++) {
			int r;
			cin >> r;
			gn.insert(r);
		}
		gs.push_back(gn);
	}
	//cout << "here\n";
	vector<vector<int>> graph(1000000 + 50);
	for (int i = 0; i < d; i++) {
		int x,y;
		cin >> x >> y;
		graph[x].push_back(y);
	}
	//cout << "here\n";
	vector<int> stack;
	for (auto i : sandwich) {
		stack.push_back(i);
	}
	while (stack.size() != 0) {
		int a = stack.back();
		stack.pop_back();
		for (auto b : graph[a]) {
			if (sandwich.find(b) == sandwich.end()) {
				sandwich.insert(b);
				stack.push_back(b);
			}
		}
	}
	//cout << "here" << "\n";
	if (sandwich.size() > m) {
		cout << "disaster\n";
		return 0;
	}
	bool good = false;
	for (auto gn : gs) {
		if (gn.size() < sandwich.size()) {
			continue;
		}
		else {
			bool gg = true;
			for (auto i : sandwich) {
				if (gn.find(i) == gn.end()) {
					gg = false;
				}
			}
			good = good or gg;
		}
	}
	if (good) {
		cout << "masterpiece\n";
	}
	else{
		cout << "disaster\n";
	}
}
