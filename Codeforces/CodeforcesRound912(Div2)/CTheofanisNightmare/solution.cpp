#include <bits/stdc++.h>

using namespace std;

int main() {
	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;

		vector<long long> a(n);
		vector<long long> pfx(n + 1);

		for (int i = 0; i < n; i++) {
			cin >> a[i];
			pfx[i] = a[i];

			if (i != 0) {
				pfx[i] += pfx[i - 1];
			}
		}

		vector<long long> ans;
		ans.push_back(0);
		long long cur = a[0];

		for (int i = 1; i < n; i++) {
			long long optA = (long long)((long long)(ans.size()) * cur) + (long long)(a[i] * ((long long)ans.size() + 1));
			long long optB = (long long)((long long)(ans.size()) * (cur + a[i])) - (pfx[n - 1] - pfx[i]);

			if (optA >= optB) {
				ans.push_back(cur);
				cur = a[i];
			}
			else {
				cur += a[i];
			}
		}

		ans.push_back(cur);

		long long p = 0;

		for (int i = 0; i < ans.size(); i++) {
			p += ans[i] * i;
		}

		cout << p << endl;
	}
}
