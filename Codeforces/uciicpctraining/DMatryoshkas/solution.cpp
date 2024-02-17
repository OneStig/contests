#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main() {
	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;

		vector<int> a(n);

		map<int, int> freq;

		for (int& i : a) {
			cin >> i;
			freq[i]++;
		}

		ll ans = 0;
		int last = 0;
		int lastsz = -2;

		for (auto it = freq.begin(); it != freq.end(); it++) {
			int cur = (*it).second;
			int cursz = (*it).first;

			if (lastsz != cursz - 1) {
				ans += cur;
			}
			else if (last < cur) {
				ans += cur - last;
			}

			last = cur;
			lastsz = cursz;
		}

		cout << ans << "\n";
	}
}
