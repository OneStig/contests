#include <bits/stdc++.h>

using namespace std;

int main() {
	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;

		vector<int> freq(n);

		for (int i = 0; i < n; i++) {
			int a;
			cin >> a;
			freq[a]++;
		}

		int ans = -1;
		int hit = 1;

		for (int i = 0; i < n; i++) {
			if (freq[i] > 1) {
				ans = i;
			}
			else if (freq[i] == 1) {
				if (hit) {
					hit--;
					ans = i;
				}
				else {
					break;
				}
			}
			else {
				break;
			}
		}

		cout << ans + 1 << '\n';
	}
}
