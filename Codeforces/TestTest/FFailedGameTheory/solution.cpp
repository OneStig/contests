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

void solve() {
    string s;
    cin >> s;
    int n = sz(s);
    
    int tot = 0;
    // p is +, b is -
    int advantage = 0;
    
    for (int i = n - 1; i >= 0; i--) {
        if (s[i] == '.') {
            tot += advantage;
        }
        else if (s[i] == 'P') {
            if (advantage >= 0) {
                advantage++;
            }
            else {
                advantage = 0;
            }
        }
        else if (s[i] == 'B') {
            if (advantage <= 0) {
                advantage--;
            } else {
                advantage = 0;
            }
        }
    }
    
    cout << (tot > 0 ? "PETER" : "BESSIE") << '\n';
}

uci main() {
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;

    while (t--) solve();
}
