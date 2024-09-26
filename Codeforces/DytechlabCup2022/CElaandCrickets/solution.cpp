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
        int n, r1, c1, r2, c2, r3, c3, x, y;
        cin >> n >> r1 >> c1 >> r2 >> c2 >> r3 >> c3 >> x >> y;

        int cx = (c1 == c2 ? c2 : c3);
        int rx = (r1 == r2 ? r2 : r3);

        // corner case, must be on the same row or same column
        if ((cx == 1 || cx == n) && (rx == 1 || rx == n)) {
            if (cx == y || rx == x) {
                cout << "YES\n";
            }
            else {
                cout << "NO\n";
            }
            continue;
        }

        // if on different colors always reachable, or in same parity row/col
        if ((x + y) % 2 != (cx + rx) % 2 || y % 2 == cx % 2) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }
    }
}
