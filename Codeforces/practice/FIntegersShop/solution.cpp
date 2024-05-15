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

void solve() {
    int n;
    cin >> n;

    vector<array<int, 3>> seg(n);
    
    for (auto& x : seg) {
        cin >> x[0] >> x[1] >> x[2];
    }

    int left = 1e10, right = -1e10;
    int li{}, ri{}, di{};

    for (int i = 0; i < n; i++) {
        auto cur = seg[i];

        if (cur[0] < left) {
            left = cur[0];
            li = i;
        }

        if (cur[1] > right) {
            right = cur[1];
            ri = i;
        }

        if (li == i && ri == i) {
            di = i;
            cout << cur[2] << '\n';
            continue;
        }

        int tmp = 1e10;

        if (seg[di][0] == left && seg[di][1] == right) {
            tmp = seg[di][2];
        }

        if (cur[0] == left && cur[2] < seg[li][2]) {
            left = cur[0];
            li = i;
        }

        if (cur[1] == right && cur[2] < seg[ri][2]) {
            right = cur[1];
            ri = i;
        }

        if (cur[2] <= tmp && cur[0] <= left && cur[1] >= right) {
            tmp = cur[2];
            di = i;
        }

        cout << min(tmp, seg[li][2] + seg[ri][2]) << '\n';
    }
}

uci main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }
}
