#include <bits/stdc++.h>

using namespace std;

#define ll long long

ll ans[200001];

int main() {
	int t;
	cin >> t;

	ans[1] = 1;

	for (int i = 2; i <= 200000; i++) {
		int cur = i;
		int cursum = 0;

		while (cur != 0) {
			cursum += cur % 10;
			cur /= 10;
		}
		ans[i] = ans[i - 1] + cursum;
	}

	while (t--) {
		int n;
		cin >> n;
		cout << ans[n] << "\n";
	}
}
