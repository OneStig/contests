#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
#include <bits/debug.h>
#endif

using namespace std;

int main() {
	int t;
	cin >> t;

	while (t--) {
		int n, k;
		cin >> n >> k;
		// 10, 4
		// 3 per

		int per = (n + k - 1) / k;

		vector<int> ans(k * per + 1);

		int order = 1;
		for (int i = 0; i < k; i++) {
			if (i % 2) {
				for (int j = (n - 1) - (n - 1 - i) % k; j >= 0; j -= k) {
					ans[j] = order;
					order++;
				}
			}
			else {
				for (int j = i; j < n; j += k) {
					ans[j] = order;
					order++;
				}
			}
		}
		
		for (int i = 0; i < n; i++) {
			cout << ans[i] << " ";
		}

		cout << endl;
	}
}
