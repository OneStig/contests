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

int n, c, q;
string s;
vector<array<int, 3>> segs;

char search(int k) {
    if (k <= n) {
        return s[k - 1];
    }

    for (int i = 1; i < sz(segs); i++) {
        if (k <= segs[i][0]) {
            return search(segs[i][2] - segs[i][0] + k);
        }
    }

    // fail here
    return 'x';
}

void solve() {
    cin >> n >> c >> q >> s;

    segs = vector<array<int, 3>>();
    segs.push_back({n, 1, n});

    int curlen = n;

    for (int i = 0; i < c; i++) {
        int l, r;
        cin >> l >> r;
        curlen += r - l + 1;
        segs.push_back({curlen, l , r});
    }

    while (q--) {
        int k;
        cin >> k;
        cout << search(k) << '\n';
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
