#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, m;
	cin >> n >> m;

	vector<int> a(n);

	for (int& i : a) {
		cin >> i;
	}

	vector<int> l(m);
	set<int> unq;
	vector<int> ans(n);

	for (int i = n - 1; i >= 0; i--) {
		unq.insert(a[i]);

		ans[i] = unq.size();
	}

	for (int& i : l) {
		cin >> i;
		cout << ans[i - 1] << endl;
	}
}
