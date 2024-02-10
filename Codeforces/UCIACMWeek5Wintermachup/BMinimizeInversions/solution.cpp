#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
#include <bits/debug.h>
#endif

using namespace std;

int main() {
	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;

		vector<array<int, 2>> perms(n);

		for (auto& i : perms) {
			cin >> i[0];
		}

		for (auto& i : perms) {
			cin >> i[1];
		}

		sort(perms.begin(), perms.end());

		for (auto& i : perms) {
			cout << i[0] << ' ';
		}

		cout << endl;

		for (auto& i : perms) {
			cout << i[1] << ' ';
		}

		cout << endl;
	}
}
