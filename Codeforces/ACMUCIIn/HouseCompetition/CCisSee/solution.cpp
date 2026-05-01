#include <bits/stdc++.h>

using namespace std;

#ifndef ONLINE_JUDGE
#include "cpp-dump/cpp-dump.hpp"
#define dbg(...) cpp_dump(__VA_ARGS__)
#else
#define dbg(...)
#endif

typedef int uci;
#define int long long
#define ld long double
#define ve vector
#define sz(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()
typedef pair<int, int> pii;

bool solve() {
    string s;
    cin >> s;

    int upos = -1;
    for (int i = 0; i < sz(s); i++) {
        if (s[i] == 'U') {
            upos = i;
            break;
        }
    }

    if (upos == -1 || upos == sz(s) - 1) return false;

    for (int i = 0; i < upos; i++) {
        if (i % 2 == 0 && s[i] != 'Y') return false;
        if (i % 2 == 1 && s[i] != 'O') return false;
    }

    string sfx = s.substr(upos + 1);

    return sfx == "CI" || sfx == "CEYE" || sfx == "SEEI" || sfx == "SEEEYE";
}

uci main() {
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;

    while (t--) {
        cout << (solve() ? "YES" : "NO") << '\n';
    }
}
