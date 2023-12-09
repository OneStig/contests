#include <bits/stdc++.h>

using namespace std;

int main() {
	int t;
	cin >> t;

	while (t--) {
		string s;
		cin >> s;

		deque<int> u, l;

		for (int i = 0; i < s.size(); i++) {
			if (s[i] == 'B') {
				if (u.size()) {
					u.pop_back();
				}
			}
			else if (s[i] == 'b') {
				if (l.size()) {
					l.pop_back();
				}
			}
			else {
				if (s[i] <= 'Z') {
					u.push_back(i);
				}
				else {
					l.push_back(i);
				}
			}
		}

		while (u.size() && l.size()) {
			if (u[0] < l[0]) {
				cout << s[u[0]];
				u.pop_front();
			}
			else {
				cout << s[l[0]];
				l.pop_front();
			}
		}

		while (u.size()) {
			cout << s[u[0]];
			u.pop_front();
		}

		while (l.size()) {
			cout << s[l[0]];
			l.pop_front();
		}
		cout << endl;
	}
}
