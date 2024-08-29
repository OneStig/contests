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
        cin >> n >> m;

        int best = 0;
        for (int i = 0; i < n; i++) {
            int l;
            cin >> l;
            set<int> a;
            while (l--) {
                int x;
                cin >> x;
                a.insert(x);
            }

            bool seen = 0;
            for (int i = 0; 1; i++) {
                if (a.find(i) == a.end()) {
                    if (seen) {
                        best = max(best, i);
                        break;
                    }

                    seen = 1;
                }
            }
        }

        int ans = (min(m, best) + 1) * best;

        if (m > best) {
            ans += m * (m + 1) / 2 - best * (best + 1) / 2;
        }

        cout << ans << '\n';
    }
}
