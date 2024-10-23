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

const ld MX_ERR = 1e6;
const ld PI = 3.1415926535897932384626;

uci main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n, q;
    cin >> n >> q;

    map<int, int> pfx;

    for (int i = 0; i < n; i++) {
        int x, y, r;
        cin >> x >> y >> r;

        ld d = sqrt(x * x + y * y);
        ld eps = asin((ld)r / (ld)d);
        ld theta = atan2(y, x);

        if (theta < 0) {
            theta += PI * 2;
        }

        ld lb = theta - eps, rb = theta + eps;
        if (lb < 0) {
            lb += PI * 2;
        }

        if (rb >= PI * 2) {
            rb -= PI * 2;
        }

        // dbg(theta, lb, rb);
        int ilb = (int)(lb * MX_ERR);
        int irb = (int)(rb * MX_ERR);

        // dbg(lb, rb);

        pfx[ilb]++;
        if (irb != 0) {
            pfx[irb]--;
        }

        if (ilb > irb) {
            pfx[0]++;
        }
    }

    vector<int> bounds(sz(pfx)), cnt(sz(pfx));
    int i = 0;
    for (auto [x, y] : pfx) {
        bounds[i] = x;
        cnt[i] = y;
        if (i != 0) {
            cnt[i] += cnt[i - 1];
        }

        i++;
    }

    // dbg(bounds);
    // dbg(cnt);

    while (q--) {
        ld alpha;
        cin >> alpha;

        int ia = (int)(alpha * MX_ERR);
        // dbg(ia);
        int ind = upper_bound(all(bounds), ia) - bounds.begin() - 1;

        if (ind == -1) {
            cout << "0\n";
            continue;
        }

        cout << cnt[ind] << '\n';
    }
}
