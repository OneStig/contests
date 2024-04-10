#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double

ld ang(char l) {
	ll count;

	if (l == ' ') {
		count = 26;
	}
	else if (l == '\'') {
		count = 27;
	}
	else {
		count = (l - 'A');
	}
	
	return (ld)(count / 28.0) * (ld)2 * (ld)M_PI;
}

int main() {
	int n;
	cin >> n;

	string asdf;
	getline(cin, asdf);

	while (n--) {
		string s;
		getline(cin, s);
		//cin >> s;

		ld dist = 1;
		ld last = ang(s[0]);

		for (int i = 1; i < s.size(); i++) {
			dist += 1;
			ld cur = ang(s[i]);
			ld diff = abs(last - cur);

			if (diff >= M_PI) {
				diff = 2 * M_PI - diff;
			}

			dist += diff * 2;
			last = cur;
		}

		cout << setprecision(20) << dist << '\n';
	}
}
