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

const int INF = 1e12;

uci main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;

        vector<pair<int, int>> rect(n);
        for (auto& x : rect) cin >> x.first >> x.second;

        vector<int> dp(k + 1, INF);
        dp[0] = 0;

        for (int i = 0; i < n; i++) {
            vector<int> ndp = dp;

            int a = rect[i].first, b = rect[i].second;
            int cost{};
            for (int make = 1; a || b; make++) {
                if (b < a) swap(a, b);
                cost += a;
                b--;

                for (int alt = 0; alt + make <= k; alt++) {
                    ndp[alt + make] = min(ndp[alt + make], dp[alt] + cost);
                }
            }

            dp = ndp;
        }

        cout << (dp[k] == INF ? -1 : dp[k]) << '\n';
    }
}

// square that is n x n
// n -> n - 1
//
// ....
// xxx.
// xxx.
// xxx.
