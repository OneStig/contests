#include <bits/stdc++.h>

using namespace std;

int main() {
	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;

		vector<int> a(n);

		for (int& i: a) {
			cin >> i;
		}

		int last[] = {a[n - 1], INT_MIN};
		int pen = 0;

		for (int i = n - 2; i >= 0; i--) {
			if (a[i] < last[0] && a[i] < last[1]) {
				pen++;

				if (last[0] > last[1]) {
					last[0] = a[i];
				}
				else {
					last[1] = a[i];
				}
			}
			else if (a[i] >= last[0] && a[i] >= last[1]) {
				if (last[0] > last[1]) {
					last[0] = a[i];
				}
				else {
					last[1] = a[i];
				}
			}
			else if (a[i] >= last[0]) {
				last[0] = a[i];
			}
			else {
				last[1] = a[i];
			}
		}

		cout << pen << endl;
	}
}

// 5 3 4 1 2
//
// 5 4 2
// 3 1
//
// 5 4 8 3 6 7 2
