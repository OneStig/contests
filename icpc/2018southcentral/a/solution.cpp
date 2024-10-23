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

pair<int, int> rot90(int x, int y) {
    return {y, -1 - x};
}

int rec(int x, int y, int depth) {
    // dbg(x, y, depth);
    if (depth == 2) {
        return 0;
    }

    int torotate{};

    int xr = x / (depth / 4), yr = y / (depth / 4);
    // dbg(xr, yr);
    if ((xr == 0 && (yr == 2 || yr == 3)) || (xr == 1 && yr == 3)) {
        y -= depth / 2;
        torotate = 3;
    }
    else if ((yr == 0 && (xr == 2 || xr == 3)) || (xr == 3 && yr == 1)) {
        x -= depth / 2;
        torotate = 1;
    }
    else if (xr == 2 || yr == 2 || (xr == 1 && yr == 1)) {
        x -= depth / 4;
        y -= depth / 4;
    }

    // dbg(torotate, x, y);
    pair<int, int> newpos = {x - depth / 4, y - depth / 4};
    // dbg(newpos);
    for (int cc = 0; cc < torotate; cc++) {
        newpos = rot90(newpos.first, newpos.second);
        // dbg(newpos);
    }
    x = newpos.first + depth / 4 , y = newpos.second + depth / 4;
    int ans = (rec(x, y, depth / 2) + (4 - torotate)) % 4;
    //dbg(torotate, ans);
    return ans;
}

void solve() {
    int x, y;
    cin >> x >> y;

    int st = 1;
    for (int i = 0; i < log2(max(x, y)) + 1; i++) {
        st *= 2;
    }

    st = max(st, 2ll);

    int ans = rec(x, y, st);
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
