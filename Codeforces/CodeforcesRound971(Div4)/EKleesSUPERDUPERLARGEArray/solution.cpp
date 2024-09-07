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

const int INF = 1e18;

uci main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;

        int ans = INF;
        int l = 0, r = n - 1;
        while (l <= r) {
            int mid = (l + r) / 2;

            int cur = ((k + mid + 1) * (k + mid) / 2 - k * (k - 1) / 2)
                    - ((k + n - 1) * (k + n) / 2 - (k + mid + 1) * (k + mid) / 2);

            ans = min(ans, abs(cur));

            if (cur == 0) break;
            if (cur < 0) {
                l = mid + 1;
            }
            else {
                r = mid - 1;
            }
        }

        cout << ans << '\n';
    }
}
