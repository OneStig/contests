#include <bits/stdc++.h>
#include <cstdlib>

using namespace std;

int main() {
	int t;
	cin >> t;

	while (t--) {
		string b;
		int n, k;

		cin >> n >> k >> b;
		int c = k % 2;

		string bc = b;

		vector<int> flips(n);

		for (int i = 0; i < n; i++) {
			if (b[i] - '0' != c) {
				b[i] = '1';
			}
			else if (b[i] - '0' == c && k > 0) {
				k--;
				b[i] = '1';
				flips[i] = 1;
			}
		}

		if (k > 0) {
			flips[n - 1] += k;
			b[n - 1] = (bc[n - 1] - '0' ^ (k % 2)) ? '1' : '0';
		}

		cout << b << endl;
		for (int i = 0; i < n; i++) {
			if (i != 0) {
				cout << ' ';
			}

			cout << flips[i];
		}

		cout << endl;
	}
}
