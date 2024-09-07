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
        int n, q;
        cin >> n >> q;

        vector<int> a(2 * n + 1);
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            a[i + n] = a[i];
        }

        for (int i = 1; i <= 2 * n; i++) {
            a[i] += a[i - 1];
        }

        while (q--) {
            int l, r;
            cin >> l >> r;
            int lg = (l - 1) / n, rg = (r - 1) / n;
            l = (l - 1) % n + 1 + lg, r = (r - 1) % n + 1 + rg;

            int ans = (rg - lg - 1) * a[n] + a[n + lg] - a[l - 1] + a[r] - a[rg];

            cout << ans << '\n';
        }
    }
}
