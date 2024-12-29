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
    int n, m, q;
    cin >> n >> m >> q;

    set<int> jok = {m};
    set<int> rf, lf;
    if (m != 1) lf.insert(m);
    if (m != n) rf.insert(m);

    while (q--) {
        int a;
        cin >> a;

        if (jok.count(a)) {
            jok.erase(a);
            jok.insert(1);
            jok.insert(n);
        
            if (!jok.count(2)) {
                rf.insert(1);
            }

            if (!jok.count(n - 1)) {
                lf.insert(1);
            }
        }

        lf = nxtL;
        rf = nxtR;
        cout << sz(jok) << ' ';
    }

    cout << '\n';
}

uci main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }
}
