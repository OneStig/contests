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

const int MAX_ANS = 4e10 + 10;

void solve() {
    int h, n;
    cin >> h >> n;

    vector<pair<int, int>> atk(n);
    for (auto& x : atk) cin >> x.first;
    for (auto& x : atk) cin >> x.second;

    int l = 1, r = MAX_ANS;
    while (r - l > 1) {
        int mid = (l + r - 1) / 2;
        int total{h};

        for (auto& [a, c] : atk) {
            total -= a * (((mid - 1) / c) + 1);
            if (total <= 0) break;
        }

        if (total <= 0) {
            r = mid + 1;
        }
        else {
            l = mid + 1;
        }
    }

    cout << l << '\n';
}

uci main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }
}
