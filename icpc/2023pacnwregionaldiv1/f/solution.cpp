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

    int n, m, s, p, q;
    cin >> n >> m >> s >> p >> q;

    map<int, set<int>> pre, need;

    for (int i = 0; i < p; i++) {
        int pselect;
        cin >> pselect;
        pre[(pselect - 1) / m + 1].insert(pselect);
    }

    for (int i = 0; i < q; i++) {
        int want;
        cin >> want;
        need[(want - 1) / m + 1].insert(want);
    }

    int ans = 0;
    int minpage = INT_MAX, maxpage = INT_MIN;
    for (int page = 1; page <= (n + m - 1) / m; page++) {
        const auto& needs = need[page];
        int onpage = m;
        if (page == (n + m - 1) / m) {
            onpage = n % m;
            if (onpage == 0) {
                onpage = m;
            }
        }
        int best = min(1 + sz(needs), 1 + onpage - sz(needs));

        int toggle = 0;
        for (int x : needs) {
            if (pre[page].find(x) == pre[page].end()) {
                toggle++;
            }
        }

        for (int x : pre[page]) {
            if (needs.find(x) == needs.end()) {
                toggle++;
            }
        }

        best = min(best, toggle);
        ans += best;
        if (best != 0) {
            minpage = min(minpage, page);
            maxpage = max(maxpage, page);
        }
    }

    // either go to min and then max, or max and then min
    if (minpage != INT_MAX) {
        ans += min(abs(minpage - s), abs(maxpage - s)) + maxpage - minpage;
    }
    cout << ans << '\n';
}
