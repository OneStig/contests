#include <bits/stdc++.h>

using namespace std;

int main() {
	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n; // n = int(input())

		map<int, long long> freq;

		for (int i = 0; i < n; i++) {
			int tmp;
			cin >> tmp;

			freq[tmp]++;
		}

		long long less = 0;

		long long ans = 0;

		for (auto it = freq.begin(); it != freq.end(); it++) {
			long long count = it->second;

			if (count >= 2) {
				ans += less * count * (count - 1) / 2;
				ans += count * (count - 1) * (count - 2) / 6;
			}
			less += count;
		}

		cout << ans << endl;
	}
}
