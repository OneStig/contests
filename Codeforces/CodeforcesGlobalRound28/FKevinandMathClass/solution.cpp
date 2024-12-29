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
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int& x : a) cin >> x;
    for (int& x : b) cin >> x;

    vector<int> need(n);

    auto checkpow = [](int a, int b, int m) {
        int cur = 1;
        while (m--) {
            if (cur > a / b) return a + 1;
            cur *= b;
        }

        return cur;
    };

    for (int i = 0; i < n; i++) {
        if (a[i] == 1) {
            need[i] = 0;
        }
        else {
            // will ceil(log2 / log2) oflow?
            int l = 0, r = 61;
            while (l != r) {
                int m = (l + r) / 2;
                if (checkpow(a[i], b[i], m) >= a[i]) {
                    r = m;
                }
                else {
                    l = m + 1;
                }
            }

            need[i] = l;
        }
    }

    int ans = 0, last = 0;
    for (int i = 0; i < n; i++) {
        ans += need[i] > last;
        last = need[i];
    }

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
