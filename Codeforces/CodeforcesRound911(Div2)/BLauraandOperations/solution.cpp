#include <bits/stdc++.h>

using namespace std;

int main() {
	int t;
	cin >> t;

	while (t--) {
		int a, b, c;
		cin >> a >> b >> c;

		cout << (b % 2 == c % 2 ? "1 " : "0 ") << (a % 2 == c % 2 ? "1 ": "0 ") << (a % 2 == b % 2 ? 1 : 0) << endl;
	}
}
