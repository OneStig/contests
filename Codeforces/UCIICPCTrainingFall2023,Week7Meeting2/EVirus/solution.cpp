#include <bits/stdc++.h>

using namespace std;

int main() {
	int t;
	cin >> t;

	while (t--) {
		int n, m;
		cin >> n >> m;
		
		vector<int> a(m);

		for (int i = 0; i < m; i++) {
			cin >> a[i];
			a[i]++;
		}

		sort(a.begin(), a.end());
	
		vector<int> gaps;

		for (int i = 0; i < m - 1; i++) {
			gaps.push_back(a[i + 1] - a[i] - 1);
		}

		if (a[0] + n - (a[m - 1] + 1) > 0) {
			gaps.push_back(a[0] + n - (a[m - 1] + 1));
		}

		sort(gaps.rbegin(), gaps.rend());

		// dead could be dead, gapedge guarantee saved
		int dead = 0, ans = n;

		for (int i = 0; i < gaps.size(); i++) {
			int gap_live = gaps[i] - dead * 2;
			if (gap_live - 1 > 0) {
				ans -= gap_live - 1;
			}
			else if (gap_live > 0) {
				ans--;
			}

			dead += 2;
		}

		cout << ans << endl;
	}
}
