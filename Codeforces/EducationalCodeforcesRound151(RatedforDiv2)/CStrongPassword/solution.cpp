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

uci main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t;
    cin >> t;

    while (t--) {
        string s, l, r;
        int m;
        cin >> s >> m >> l >> r;

        // int combs = 1;
        // for (int i = 0; i < m; i++) {
        //     combs *= r[i] - l[i] + 1;
        // }

        int layer{}, layerc{};
        vector<bool> cur(10);
        for (char& c : s) {
            if (layer >= m) break;
            if (l[layer] <= c && c <= r[layer]) {
                if (!cur[c - '0']) {
                    cur[c - '0'] = 1;
                    layerc++;
                }

                if (layerc == r[layer] - l[layer] + 1) {
                    layer++;
                    layerc = 0;
                    cur = vector<bool>(10);
                }
            }
        }

        if (layer == m) {
            cout << "NO\n";
        }
        else {
            cout << "YES\n";
        }
    }
}
