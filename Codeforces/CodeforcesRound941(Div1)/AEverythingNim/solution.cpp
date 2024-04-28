#include <bits/stdc++.h>

using namespace std;

int main() {
	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;

		set<int> a;

		while (n--) {
			int x;
			cin >> x;
			a.insert(x);
		}

		a.insert(0);

		vector<int> piles(a.begin(), a.end());

		bool yn = 1;

		for (int i = piles.size() - 2; i > 0; i--) {
			if (piles[i] - piles[i - 1] != 1) {
				yn = 1;
			}
			else {
				yn = !yn;
			}

		}

		cout << (yn ? "Alice" : "Bob") << '\n';
	}
}
