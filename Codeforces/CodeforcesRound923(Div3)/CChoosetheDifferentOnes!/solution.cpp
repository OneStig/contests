#include <bits/stdc++.h>

using namespace std;

int main() {
	int t;
	cin >> t;

	while (t--) {
		int n, m, k;
		cin >> n >> m >> k;

		vector<int> a(n), b(m);

		for (int& i : a) {
			cin >> i;
		}

		for (int& i : b) {
			cin >> i;
		}

		sort(a.begin(), a.end());
		sort(b.begin(), b.end());


	}
}
