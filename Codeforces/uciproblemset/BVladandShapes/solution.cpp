#include <bits/stdc++.h>

using namespace std;

int main() {
	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;

		vector<string> s(n);

		set<int> nums;

		for (string& x : s) {
			cin >> x;

			int sum = 0;
			for (int i = 0; i < n; i++) {
				sum += x[i] - '0';
			}

			if (sum != 0) {
				nums.insert(sum);
			}
		}

		if (nums.size() == 1) {
			cout << "SQUARE\n";
		}
		else {
			cout << "TRIANGLE\n";
		}
	}
}
