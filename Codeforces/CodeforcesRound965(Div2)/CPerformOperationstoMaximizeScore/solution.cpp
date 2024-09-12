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

const int INF = 2e9;

uci main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;

        vector<pair<int, bool>> a(n);
        for (auto& x : a) cin >> x.first;
        for (auto& x : a) cin >> x.second;
        sort(all(a));

        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (a[i].second) {
                int med;
                if (i < n / 2) {
                    med = a[n / 2].first;
                }
                else {
                    med = a[n / 2 - 1].first;
                }

                ans = max(ans, a[i].first + k + med);
            }
        }

        if (!a[n - 1].second) {
            int l = 0, r = INF;
            while (l < r) {
                int mid = (l + r + 1) / 2;
                int above{}, remain = k;

                for (int i = n - 2; i >= 0; i--) {
                    if (a[i].first >= mid) {
                        above++;
                        continue;
                    }

                    if (a[i].second) {
                        if (mid - a[i].first > remain) break;
                        above++;
                        remain -= mid - a[i].first;
                    }
                }

                if (above >= (n - 1) / 2 + 1) {
                    // good to go
                    l = mid;
                }
                else {
                    r = mid - 1;
                }
            }

            ans = max(ans, l + a[n - 1].first);
        }

        cout << ans << '\n';
    }
}
