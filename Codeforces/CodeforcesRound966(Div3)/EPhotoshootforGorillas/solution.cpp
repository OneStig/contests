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
        int n, m, k, w;
        cin >> n >> m >> k >> w;

        vector<int> a(w);
        for (int& x : a) cin >> x;

        vector<int> spots;
        spots.reserve(n * m);
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                int l = max(1ll, i - k + 1), r = min(i, n - k + 1);
                int horiz = r - l + 1;
                int d = max(1ll, j - k + 1), u = min(j, m - k + 1);
                int vert = u - d + 1;
                spots.push_back(horiz * vert);
            }
        }

        sort(spots.rbegin(), spots.rend());
        sort(a.rbegin(), a.rend());

        int ans{};
        for (int i = 0; i < w; i++) {
            ans += spots[i] * a[i];
        }

        cout << ans << '\n';
    }
}
