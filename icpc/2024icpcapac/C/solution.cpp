#include <bits/stdc++.h>

using namespace std;

#define ull unsigned long long

int main() {
	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;

		vector<int> a(n);

		int mx = INT_MIN;
		int mxi = -1;

		for (int i = 0; i < n; i++) {
			cin >> a[i];

			if (a[i] > mx) {
				mx = a[i];
				mxi = i;
			}
		}

		ull num = 0;

	}
}
