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

ld dist(pair<int, int> a, pair<int, int> b) {
    return sqrtl((a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second));
}

uci main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n, m, p;
    cin >> n >> m >> p;
    vector<bool> isn(n, 1), ism(m, 1), isp(p, 1);

    vector<pair<int, int>> ns(n), ms(m), ps(p);

    for (auto& x : ns) cin >> x.first >> x.second;
    for (auto& x : ms) cin >> x.first >> x.second;
    for (auto& x : ps) cin >> x.first >> x.second;

    ld ans = 0;
    vector<pair<ld, pair<int, int>>> nm;
    nm.reserve(n * m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            nm.push_back({dist(ns[i], ms[j]), {i, j}});
        }
    }
    vector<pair<ld, pair<int, int>>> np;
    np.reserve(n * p);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < p; j++) {
            np.push_back({dist(ns[i], ps[j]), {i, j}});
        }
    }

    sort(all(nm));
    sort(all(np));

    // dbg(nm, np);

    for (auto& x : nm) {
        if (isn[x.second.first] && ism[x.second.second]) {
            isn[x.second.first] = 0;
            ism[x.second.second] = 0;
            ans += x.first;
        }
    }

    isn = vector<bool>(n, 1);

    for (auto& x : np) {
        if (isn[x.second.first] && isp[x.second.second]) {
            isn[x.second.first] = 0;
            isp[x.second.second] = 0;
            ans += x.first;
        }
    }

    cout << fixed << setprecision(10) << ans << '\n';
}
