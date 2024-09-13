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

    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n;
        vector<int> a(n), b(n);
        set<int> inb;
        for (int& x : a) cin >> x;
        for (int i = 0; i < n; i++) {
            cin >> b[i];
            inb.insert(b[i]);
        }

        cin >> m;
        vector<int> d(m);
        for (int& x : d) cin >> x;

        int bad{};
        map<int, int> need;
        for (int i = 0; i < n; i++) {
            if (a[i] != b[i]) {
                need[b[i]]++;
                bad++;
            }
        }

        for (int i = 0; i < m; i++) {
            if (need[d[i]] != 0) {
                need[d[i]]--;
                bad--;
            }
        }

        if (!inb.contains(d[m - 1])) {
            bad = 1;
        }

        cout << (bad ? "NO" : "YES") << '\n';
    }
}
