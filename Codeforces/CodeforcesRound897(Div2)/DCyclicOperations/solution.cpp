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

uci main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;

        vector<int> b(n + 1);
        for (int i = 1; i <= n; i++) cin >> b[i];

        vector<int> depth(n + 1);
        vector<int> loops(n + 1);
        bool yes = 1;

        if (k == 1) {
            yes = 1;
            for (int i = 1; i <= n; i++) {
                if (b[i] != i) {
                    yes = 0;
                    break;
                }
            }

            cout << (yes ? "YES\n" : "NO\n");
            continue;
        }

        for (int i = 1; i <= n; i++) {
            if (loops[i]) continue;

            int cur = i;
            int loopsz = 1;
            depth[cur] = 1;
            while (1) {
                int nxt = b[cur];
                if (depth[nxt]) {
                    if (loops[nxt]) {
                        loopsz = loops[nxt];
                    } else {
                        loopsz = depth[cur] - depth[nxt] + 1;
                    }
                    break;
                }

                depth[nxt] = depth[cur] + 1;
                cur = nxt;
            }

            if (loopsz != k) {
                yes = 0;
                break;
            }

            int ncur = i;
            while (!loops[ncur]) {
                loops[ncur] = loopsz;
                ncur = b[ncur];
            }
        }

        cout << (yes ? "YES\n" : "NO\n");
    }
}
