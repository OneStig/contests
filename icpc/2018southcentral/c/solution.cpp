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
    string a, b;
    cin >> a >> b;
    int n = sz(a);

    set<array<uci, 26>> bs;

    for (int i = 0; i < n; i++) {
        array<uci, 26> cur;
        for (int k = 0; k < 26; k++) {
            cur[k] = 0;
        }

        for (int j = i; j < n; j++) {
            cur[b[j] - 'a']++;
            bs.insert(cur);
        }
    }

    int ans{};
    int b1 = -1;
    for (int i = 0; i < n; i++) {
        array<uci, 26> cur;
        for (int k = 0; k < 26; k++) {
            cur[k] = 0;
        }
        for (int j = i; j < n; j++) {
            cur[a[j] - 'a']++;
            if (bs.contains(cur) && j - i + 1 > ans) {
                ans = j - i + 1;
                b1 = i;
            }
        }
    }

    if (ans == 0) {
        cout << "NONE\n";
    }
    else {
        cout << a.substr(b1, ans) << '\n';
    }
}

uci main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }
}
