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

int maxoffpal(string& s, int i) {

}

int maxcenpal(string& s, int i) {
    int n = sz(s);
    int len = 0;
    while (i + len + 1 < n && i - len - 1 >= 0 && s[i + len + 1] == s[i - len - 1]) {
        len++;
    }

    return len;
}

int solve(string s) {
    int n = sz(s);
    int ans = 1;

    for (int i = 1; i < n; i++) {
        // absolute center
        int len = maxcenpal(s, i);
        ans = max(ans, 1 + 2 * len);

        if (i - len - 1 >= 0) {
            char orig = s[i + len + 1];
            char need = s[i - len - 1];
        
            s[i + len + 1] = need;
            
            int len2 = maxcenpal(s, i);
        }
        
        // right center
    }
}

uci main() {
    cin.tie(0)->sync_with_stdio(0);

    string s;
    cin >> s;

    int ans1 = solve(s);
    reverse(all(s));
    int ans2 = solve(s);
    cout << max(ans1, ans2);
}
