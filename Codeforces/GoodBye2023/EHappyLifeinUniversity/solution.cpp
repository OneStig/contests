#include <bits/stdc++.h>

using namespace std;

vector<int> tree[300001];
int a[300001];

set<int> activ[300001];
long long ans;

void search(int x) {
	if (tree[x].size() == 0) {

	}
}

void solve() {
	int n;
	cin >> n;

	for (int i = 2; i <= n; i++) {
		int p;
		cin >> p;
		tree[p].push_back(i);
	}

	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	cout << ans << endl;
}

int main() {
	int t;
	cin >> t;

	while (t--) {
		ans = 0;
		memset(tree, 0, sizeof(tree));
		solve();
	}
}
