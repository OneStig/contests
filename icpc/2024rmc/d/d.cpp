#include <bits/stdc++.h>

using namespace std;

typedef int uci;
#define int long long
#define sz(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()

uci main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

	set<string> emotions = {":)", ":-)", ":-(", ";-)", "xD", "^_^", "-_-", "^o^", "^^;", "(..)"};
	set<char> st;

	auto ans = [&](string s) {
		int n = sz(s);
		int cnt = 0;
		for(int i = 0; i < n; ++i) {
			//bool ok = true;
			for(int j = 2; j <= 4; ++j) {
				if(emotions.find(s.substr(i, j)) != emotions.end()) {
					// cnt++;
					i += j - 1;
					// ok = false;
					break;
				}
			}

			//if(ok) {
			cnt++;
			//}
		}

		// if (cnt == 3) {
		// 	cerr << s << '\n';
		// }

		return cnt;
	};


	for(auto x : emotions) {
		for(auto c : x) {
			st.insert(c);
		}
	}
	string s;
	getline(cin, s);

	set<char> initial;
	for(auto c : s) {
		initial.insert(c);
	}

	st.insert('z');

	int n = sz(s);
	int minim = ans(s);
	int maxim = ans(s);
	for(char first : initial) {
		for(auto second : st) {
			if(first != second) {
				string t = s;
				for(int j = 0; j < n; ++j) {
					if(t[j] == first) {
						t[j] = second;
					}
				}

				minim = min(minim, ans(t));
				maxim = max(maxim, ans(t));
			}
		}
	}

	cout << minim << " " << maxim << "\n";
}
