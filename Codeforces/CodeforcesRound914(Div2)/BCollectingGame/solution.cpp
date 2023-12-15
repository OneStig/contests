#include <bits/stdc++.h>

using namespace std;

int main() {
	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;

		vector<pair<long long, int>> a(n);
		vector<long long> sums(n);

		for (int i = 0; i < n; i++) {
			long long tmp;
			cin >> tmp;
			a[i] = {tmp, i};
		}

		sort(a.begin(), a.end());

		sums[0] = a[0].first;

		for (int i = 1; i < n; i++) {
			sums[i] = sums[i - 1] + a[i].first;
		}

		vector<int> ans(n);
		ans[n - 1] = n - 1;
		vector<int> actual_ans(n);
		actual_ans[a[n - 1].second] = n - 1;

		for (int i = n - 2; i >= 0; i--) {
			if (sums[i] >= a[i + 1].first) {
				ans[i] = ans[i + 1];
			}
			else {
				ans[i] = i;
			}

			actual_ans[a[i].second] = ans[i];
		}

		for (int i = 0; i < n; i++) {
			if (i != 0) {
				cout << " ";
			}

			cout << actual_ans[i];
		}

		cout << endl;
	}
}
