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
        int n;
        cin >> n;

        vector<int> a(n), d(n), l(n), r(n);
        for (int& x : a) cin >> x;
        for (int& x : d) cin >> x;

        set<int> cands;
        for (int i = 0; i < n; i++) {
            cands.insert(i);
            l[i] = i - 1;
            r[i] = i + 1;
        }

        for (int rnd = 0; rnd < n; rnd++) {
            vector<int> dead;

            for (int cur : cands) {
                int dmg{};
                if (l[cur] >= 0) dmg += a[l[cur]];
                if (r[cur] < n) dmg += a[r[cur]];

                if (dmg > d[cur]) {
                    dead.push_back(cur);
                }
            }

            set<int> newc;

            for (int cur : dead) {
                newc.erase(cur);
                if (l[cur] >= 0) {
                    r[l[cur]] = r[cur];
                    newc.insert(l[cur]);
                }

                if (r[cur] < n) {
                    l[r[cur]] = l[cur];
                    newc.insert(r[cur]);
                }
            }

            cands = newc;
            cout << sz(dead) << ' ';
        }
        cout << '\n';
    }
}
