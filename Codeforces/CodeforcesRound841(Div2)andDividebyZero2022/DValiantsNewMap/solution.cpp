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

        vector<vector<int>> a(n + 1, vector<int>(m + 1));
        for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }

        int l = 1, r = n;
        int ans = 1;
        while (l <= r) {
            int mid = (l + r) / 2;

            bool good = 0;
            vector<vector<int>> pfx(n + 1, vector<int>(m + 1));
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= m; j++) {
                    if (a[i][j] >= mid) {
                        pfx[i][j]++;
                    }

                    pfx[i][j] += pfx[i - 1][j] + pfx[i][j - 1] - pfx[i - 1][j - 1];

                    if (i >= mid && j >= mid) {
                        if (pfx[i][j] - pfx[i - mid][j] - pfx[i][j - mid] + pfx[i - mid][j - mid] == mid * mid) {
                            good = 1;
                            break;
                        }
                    }
                }

                if (good) break;
            }

            if (good) {
                ans = max(ans, mid);
                l = mid + 1;
            }
            else {
                r = mid - 1;
            }
        }

        cout << ans << '\n';
    }
}

// {0, 0, 0, 0, 0, 0, 0}
// {0, 1, 2, 3, 4, 5, 6}
// {0, 2, 4, 6, 8, 10, 12}
// {0, 3, 6, 9, 12, 15, 18}
// {0, 4, 8, 12, 16, 20, 24},
// {0, 5, 10, 15, 20, 25, 30}}
