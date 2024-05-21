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

#define ll long long
typedef int uci;
#define int long long
#define ld long double
#define sz(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()

int query(int l, int x) {
    int r;
    cout << "? " << l << " " << x << endl;
    cin >> r;

    if (r == -1) {
        cout << "! -1" << endl;
    }

    return r;
}

void pans(int a) {
    cout << "! " << a << endl;
    int x;
    cin >> x;

    if (x == -1) {
        cout << "! -1" << endl;
    }
}

void solve() {
    int n, k;
    cin >> n >> k;

    // first lets find the max

    int mx{};

    for (int x = n * n; x >= n; x -= n) {
        int q = query(1, x);
        if (q != n + 1) {
            mx = x / q;
            break;
        }
    }

    int ans = -1;
    for (int m = mx * n; m >= mx; m -= mx) {
        if (n / k * mx < m) continue;

        int left = 1;
        int q{};
        for (int i = 0; i < k; i++) {
            if (left > n) {
                q = -1;
                break;
            }

            q = query(left, m);

            if (q == n + 1) {
                q = -1;
                break;
            }

            left = q + 1;
        }

        if (q == n) {
            ans = m;
            break;
        }
    }

    pans(ans);
}

uci main() {
    int t;
    cin >> t;

    while (t--) {
        solve();
    }
}
