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

    int n;
    cin >> n;

    int mx = sqrt(n);
    int ans{};
    for (int a = 0; a <= mx; a++) {
        int a2 = a * a, aneg = (a < 0 ? -1 : 1);
        for (int b = -abs(a); b <= abs(a); b++) {
            int b2 = b * b, bneg = (b < 0 ? -1 : 1);
            if (abs(a) == abs(b) && a != b) continue;

            for (int c = -abs(b); c <= abs(b); c++) {
                int c2 = c * c, cneg = (c < 0 ? -1 : 1);
                if (abs(c) == abs(b) && b != c) continue;

                int d2 = n - (a2 * aneg + b2 * bneg + c2 * cneg);
                int dneg = (d2 < 0 ? -1 : 1);
                // dbg(a, b, c, d2);
                // 1. d2 has to be perfect square
                // 2. if abs(d) == abs(c), sign has to be the same

                int d = sqrt(abs(d2));
                if (d * d != abs(d2)) continue;
                if (d > abs(c)) continue;
                if (abs(d2) == c2 && (d2 < 0 != c < 0)) continue;

                int test = a2 * aneg + b2 * bneg + c2 * cneg + d * d * dneg;
                if (test != n || b2 > a2 || c2 > b2 || d * d > c2 ||
                    (a2 == b2 && aneg != bneg) || (b2 == c2 && bneg != cneg) || (c2 == d * d && cneg != dneg)) {
                    cout << "bad" << '\n';
                    dbg(a, b, c, d * dneg);
                }

                ans++;
            }
        }
    }

    cout << ans << '\n';
}
