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

		if (a[n - 1]) {
			cout << "NO" << endl;
			continue;
		}

		cout << "YES" << endl;

		vector<int> ans;

		int count = 0;
		for (int i = 0; i < n; i++) {
			if (a[i]) {
				count++;
			}
			else {
				ans.push_back(count);
				count = 0;
			}
		}


		for (int i = ans.size() - 1; i >= 0; i--) {
			for (int j = 0; j < ans[i]; j++) {
				cout << "0 ";
			}

			cout << ans[i] << " ";
		}

		cout << endl;
	}
}
