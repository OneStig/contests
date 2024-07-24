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
        int n, tot{};
        cin >> n;

        vector<vector<int>> nums(3, vector<int>(n));
        vector<vector<int>> pfx(3, vector<int>(n + 1));

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < n; j++) {
                cin >> nums[i][j];
                pfx[i][j + 1] = pfx[i][j] + nums[i][j];
                tot += nums[i][j];
            }
        }

        int thresh = (tot / 3 + 2) / 3;

        bool found = 0;
        for (int a = 0; a < 3; a++) {
            if (found) break;
            for (int b = 0; b < 3; b++) {
                if (a != b) {
                    int c = 3 - a - b;

                    array<pair<int, int>, 3> ans;

                    auto it = lower_bound(all(pfx[a]), thresh);
                    if (it == pfx[a].end()) continue;
                    int cutA = it - pfx[a].begin();
                    ans[a] = {1, cutA};

                    it = lower_bound(all(pfx[b]), thresh + pfx[b][cutA]);
                    if (it == pfx[b].end()) continue;
                    int cutB = it - pfx[b].begin();
                    ans[b] = {cutA + 1, cutB};

                    if (pfx[c][n] - pfx[c][cutB] < thresh) continue;
                    ans[c] = {cutB + 1, n};

                    found = 1;
                    cout << ans[0].first << ' ' << ans[0].second << ' '
                        << ans[1].first << ' ' << ans[1].second << ' '
                        << ans[2].first << ' ' << ans[2].second << '\n';
                    break;
                }
            }
        }

        if (!found) {
            cout << -1 << '\n';
        }
    }
}
