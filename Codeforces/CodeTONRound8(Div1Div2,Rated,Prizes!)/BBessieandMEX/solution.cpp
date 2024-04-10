#include <bits/stdc++.h>

using namespace std;

int main() {
	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;

		vector<int> a(n);
		
		for (int& i : a) {
			cin >> i;
		}

		vector<int> ans(n);

		int cur = n;

		set<int> removed;

		for (int i = n - 1; i >= 0; i--) {
			ans[i] = cur - a[i];
			removed.insert(ans[i]);
			cur = *(removed.begin());
		}

		for (int& x : ans) {
			cout << x << ' ';
		}

		cout << '\n';
	}
}
