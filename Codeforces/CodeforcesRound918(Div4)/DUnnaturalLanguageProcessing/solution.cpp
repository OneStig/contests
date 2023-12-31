#include <bits/stdc++.h>

using namespace std;

map<char, bool> vowel = {
	{'a', 1},
	{'b', 0},
	{'c', 0},
	{'d', 0},
	{'e', 1},
};

int main() {
	int t;
	cin >> t;

	while (t--) {
		int n;
		string s;
		cin >> n >> s;

		unordered_set<int> dots;

		for (int i = n - 1; i >= 0; i--) {
			if (vowel[s[i]]) {
				dots.insert(i - 2);
				i--;
			}
			else {
				dots.insert(i - 3);
				i -= 2;
			}
		}

		for (int i = 0; i < n; i++) {
			cout << s[i];

			if (dots.find(i) != dots.end()) {
				cout << '.';
			}
		}
		
		cout << endl;
	}
}
