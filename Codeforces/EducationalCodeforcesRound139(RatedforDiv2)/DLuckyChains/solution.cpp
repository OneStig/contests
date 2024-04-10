#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b) {
	if (b == 0) {
		return a;
	}

	return gcd(b, a % b);
}

int main() {
	int n;

	while (n--) {
		int x, y;
		cin >> x >> y;

		if (y - x == 1) {
			cout << "-1\n";
			continue;
		}

		if (gcd(y, x) == 1) {
			cout << "0\n";
			continue;
		}

	}
}
