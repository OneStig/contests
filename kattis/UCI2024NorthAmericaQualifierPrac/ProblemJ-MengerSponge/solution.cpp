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

    int l;
    cin >> l;

    int x1, x2, y1, y2, z1, z2;
    cin >> x1 >> x2 >> y1 >> y2 >> z1 >> z2;

    if (x1 > x2 || y1 > y2 || z1 > z2) {
        cout << "0\n";
        return 0;
    }

    bool yes = 1;
    for (int i = 0; i < l; i++) {
        if (x2 % 3 != 0) {
            x1 *= 3;
            x2 *= 3;
        }

        if (y2 % 3 != 0) {
            y1 *= 3;
            y2 *= 3;
        }

        if (z2 % 3 != 0) {
            z1 *= 3;
            z2 *= 3;
        }

        int hole = (x1 > x2 / 3 && x1 < 2 * x2 / 3)
                + (y1 > y2 / 3 && y1 < 2 * y2 / 3)
                + (z1 > z2 / 3 && z1 < 2 * z2 / 3);

        if (hole >= 2) {
            yes = 0;
            break;
        }

        // shift the coordinate to the sub third
        x1 = x1 % (x2 / 3) * 3;
        y1 = y1 % (y2 / 3) * 3;
        z1 = z1 % (z2 / 3) * 3;
    }

    cout << yes << '\n';
}
