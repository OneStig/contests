#include <bits/stdc++.h>

using namespace std;

#define ull unsigned long long

int main() {
	int t;
	cin >> t;

	while (t--) {
		ull a, b, r;
		cin >> a >> b >> r;

		if (a == b) {
			cout << 0 << endl;
			continue;
		}

		if (a < b) {
			swap(a, b);
		}

		ull ans = 0;

		bool hit = 0;

		for (int i = 63; i >= 0; i--) {
			ull cur = (ull)1 << i;
			bool aa = (a >> i) % 2;
			bool bb = (b >> i) % 2;

			if (aa != bb) {
				if (hit && aa && ans + cur <= r) {
					ans += cur;
				}

				hit = 1;
			}
		}

		cout << (a ^ ans) - (b ^ ans) << endl;
	}
}
