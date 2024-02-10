#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
#include <bits/debug.h>
#endif

using namespace std;

int main() {
	int n, m;
	cin >> n >> m;

	vector<int> a(n);

	for (int& i : a) {
		cin >> i;
	}

	vector<int> dec(n), inc(n);
	inc[0] = -1;

	for (int i = 1; i < n; i++) {
		if (a[i] > a[i - 1]) {
			inc[i] = i;
		}
		else {
			inc[i] = inc[i - 1];
		}
	}

	dec[n - 1] = n;

	for (int i = n - 2; i >= 0; i--) {
		if (a[i] > a[i + 1]) {
			dec[i] = i;
		}
		else {
			dec[i] = dec[i + 1];
		}
	}

	//debug(dec, inc);
	while (m--) {
		int l, r;
		cin >> l >> r;
		l--, r--;

		if (dec[l] >= inc[r]) {
			cout << "Yes" << endl;
		}
		else {
			cout << "No" << endl;
		}
	}
}
