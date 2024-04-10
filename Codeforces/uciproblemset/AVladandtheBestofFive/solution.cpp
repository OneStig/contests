#include <bits/stdc++.h>

using namespace std;

int main() {
	int t;
	cin >> t;

	while (t--) {
		string s;
		cin >> s;
		int a = 0;

		for (int i = 0; i < 5; i++) {
			a += s[i] == 'A';
		}

		cout << (a > 2 ? "A" : "B") << "\n";
	}
}
