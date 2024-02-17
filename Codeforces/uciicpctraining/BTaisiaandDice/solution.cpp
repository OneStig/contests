#include <bits/stdc++.h>

using namespace std;

int main() {
	int t;
	cin >> t;

	while (t--) {
		int n, s, r;
		cin >> n >> s >> r;

		vector<int> ans(n - 1, 1);
		int max = s - r - 1;
		ans.push_back(s - r);
		r -= n - 1;

		for (int i = 0; i < n - 1; i++) {
			int cur = min(r, max);
			ans[i] += cur;
			r -= cur;
		}

		for (int& x : ans) {
			cout << x << " ";
		}

		cout << "\n";
	}
}
