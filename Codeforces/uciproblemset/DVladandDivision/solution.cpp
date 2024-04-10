#include <bits/stdc++.h>

using namespace std;

int main() {
	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;

		int ans = 0;
		map<int, int> found;

		while (n--) {
			int a;
			cin >> a;

			int opp = a ^ INT_MAX;
			if (found[opp] != 0) {
				found[opp]--;
			}
			else {
				found[a]++;
				ans++;
			}
		}

		cout << ans << "\n";
	}
}
