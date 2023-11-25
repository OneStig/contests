#include <bits/stdc++.h>

using namespace std;

int main() {
	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;
		int mn = INT_MAX;
		int mx = INT_MIN;
		int a;

		for (int i = 0; i < n; i++) {
			cin >> a;
			mn = min(mn, a);
			mx = max(mx, a);
		}

		int ans = 0;
		vector<int> moves;

		while (mn != mx) {
			if (mn % 2 != 0) {
				mn++;
				mx++;
				moves.push_back(1);
			}
			else {
				moves.push_back(0);
			}

			mn /= 2;
			mx /= 2;
			ans++;
		}

		cout << ans << endl;

		if (ans <= n) {
			for (int i = 0; i < moves.size(); i++) {
				if (i != 0) {
					cout << " ";
				}
				cout << moves[i];
			}

			if (moves.size()) {
				cout << endl;
			}
		}
	}
}
