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

// "incomplete" configurations
// c_0  c_1
// x--  xx-
// xx-  x--

// "complete" configurations
// c_2  c_3  c_4
// xxx  -xx  --x
// yyy  --x  -xx

const int INF = 1e9;

void solve() {
    int n;
    cin >> n;
    n /= 3;
    string sa, sb;
    cin >> sa >> sb;

    array<int, 3> dp = {-INF, -INF, 0};

    auto a = [&](int pos) -> int {
        return sa[pos] == 'A';
    };

    auto b = [&](int pos) -> int {
        return sb[pos] == 'A';
    };

    for (int i = 0; i < n; i++) {
        int j = i * 3;
        array<int, 3> ndp;

        ndp[0] = dp[2] + (a(j) + b(j) + b(j + 1) > 1);
        ndp[1] = dp[2] + (b(j) + a(j) + a(j + 1) > 1);

        if (i != 0) {
            ndp[0] = max(ndp[0], dp[0] + (a(j - 2) + a(j - 1) + a(j) > 1) + (b(j - 1) + b(j) + b(j + 1) > 1));
            ndp[1] = max(ndp[1], dp[1] + (b(j - 2) + b(j - 1) + b(j) > 1) + (a(j - 1) + a(j) + a(j + 1) > 1));
        }

        ndp[2] = max({
            dp[2] + (a(j) + a(j + 1) + a(j + 2) > 1) + (b(j) + b(j + 1) + b(j + 2) > 1),
            ndp[0] + (a(j + 1) + a(j + 2) + b(j + 2) > 1),
            ndp[1] + (b(j + 1) + b(j + 2) + a(j + 2) > 1)
        });

        dp = ndp;
    }

    cout << dp[2] << '\n';
}

uci main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }
}
