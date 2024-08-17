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
        int n, m, q;
        cin >> n >> m;

        vector<pair<int, int> > bounds(m);

        for (auto& x : bounds) {
            cin >> x.first >> x.second;
        }

        cin >> q;
        vector<int> change(q);
        for (int& x : change) cin >> x;

        int ans = q + 1;
        int l = 1, r = q + 1;
        while (l < r) {
            int mid = (l + r) / 2;
            if (mid > q) break;

            vector<int> nums(n + 1), pfx(n + 1);
            for (int i = 0; i < mid; i++) {
                nums[change[i]] = 1;
            }

            for (int i = 1; i <= n; i++) {
                pfx[i] = pfx[i - 1] + nums[i];
            }

            bool good = 0;
            for (auto& b : bounds) {
                int ones = pfx[b.second] - pfx[b.first - 1];
                if (ones > b.second - b.first + 1 - ones) {
                    good = 1;
                    break;
                }
            }

            if (good) {
                ans = min(ans, mid);
                r = mid;
            }
            else {
                l = mid + 1;
            }
        }

        cout << (ans == q + 1 ? -1 : ans) << '\n';
    }
}
