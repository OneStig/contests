#include <bits/stdc++.h>

using namespace std;

template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }

#ifndef ONLINE_JUDGE
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

typedef int uci;
#define int long long
#define ld long double
#define sz(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()

void solve() {
    string s;
    cin >> s;
    int n = sz(s);

    bool found = 0;
    for (int offset = 0; offset < 7; offset++) {
        set<char> bef;
        for (int i = 0; i < offset; i++) {
            bef.insert(s[i]);
        }

        if (sz(bef) != offset) {
            continue;
        }

        bool good = 1;

        for (int i = offset; i < n; i += 7) {
            int expect = min(n - i, 7ll);

            set<char> cur;
            for (int j = i; j < i + 7 && j < n; j++) {
                cur.insert(s[j]);
            }

            if (sz(cur) != expect) {
                good = 0;
                break;
            }
        }

        if (good) {
            found = 1;
            break;
        }
    }

    cout << found << '\n';
}

uci main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }
}
