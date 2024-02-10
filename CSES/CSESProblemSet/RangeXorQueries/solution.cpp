#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, q;
	cin >> n >> q;

	vector<int> a(n + 1);
	vector<int> p(n + 1);

	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		p[i] = p[i - 1] ^ a[i];
	}

	while (q--) {
		int a, b;
		cin >> a >> b;

		cout << (p[b] ^ p[a - 1]) << endl;
	}
}
