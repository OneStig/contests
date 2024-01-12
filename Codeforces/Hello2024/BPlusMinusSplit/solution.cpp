#include <bits/stdc++.h>

using namespace std;

int main() {
	int t;
	cin >> t;

	while (t--) {
		int n;
		string s;
		cin >> n >> s;
		
		int a = 0, b = 0;

		for (int i = 0; i < n; i++) {
			if (s[i] == '-') {
				a++;
			}
			else {
				b++;
			}
		}

		cout << (max(a, b) - min(a, b)) << endl;
	}
}
