#include <bits/stdc++.h>

using namespace std;

int main() {
	int t;
	cin >> t;

	while(t--) {
		int n;
		cin >> n;

		vector<int> a(n);

		for (int& i : a) {
			cin >> i;
		}

		vector<int> alph(26);

		for (int i = 0; i < n; i++) {
			for (int l = 0; l < 26; l++) {
				if (alph[l] == a[i]) {
					cout << (char)('a' + l);
					alph[l]++;
					break;
				}
			}
		}

		cout << endl;
	}
}
