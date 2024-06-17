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
    int n, c, d;
    cin >> n >> c >> d;

    vector<int> a(n);
    vector<int> pfx(n);

    for (int& x : a) cin >> x;

    sort(a.rbegin(), a.rend());

    if (a[0] * d < c) {
        cout << "Impossible\n";
        return;
    }
    pfx[0] = a[0];

    for (int i = 1; i < n; i++) {
        pfx[i] = a[i] + pfx[i - 1];
    }

    if (pfx[min(n - 1, d - 1)] >= c) {
        cout << "Infinity\n";
        return;
    }

    int ans{};

    int l = 0, r = d + 1;
    while (r - l > 1) {
        int mid = (l + r) / 2;
        int coins = d / (mid + 1) * pfx[min(mid, n - 1)];

        if (d % (mid + 1)) {
            coins += pfx[min(d % (mid + 1) - 1, n - 1)];
        }

        if (coins >= c) {
            l = mid;
        }
        else {
            r = mid;
        }
    }

    ans = l;
    cout << ans << '\n';
}

uci main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }
}
