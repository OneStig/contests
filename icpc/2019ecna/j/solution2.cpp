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

const int INF = 1e9;

uci main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> a(n);
    for(int i = 0; i < n; ++i){
        cin >> a[i].second >> a[i].first;
        // first = deadline, second = pages
    }

    sort(all(a));
    dbg(a);

    int ans = INF;
    int l = 0, r = INF;
    while (l < r){
        int mid = (r + l) / 2;
        vector<array<int, 2>> dp(n, {INF, INF});

        // 0 - we dont take, 1 - we take
        dp[0][0] = 1;
        dp[0][1] = (((a[0].second + mid - 1) / mid) <= a[0].first ? 0 : 1);

        for(int i = 1; i < n; ++i){
            int x = ((a[i].second + mid - 1) / mid);

            dp[i][0] = min(dp[i - 1][0], dp[i - 1][1]) + 1;

            if (a[i].first - x < 0) {
                continue;
            }

            if (a[i].first - x < a[0].first) {
                dp[i][1] = i;
                continue;
            }

            int L = 0, R = i - 1;
            while(L < R){
                int MID = (R + L + 1) / 2;
                if(a[MID].first <= a[i].first - x){
                    L = MID;
                }
                else{
                    R = MID - 1;
                }
            }

            dbg(i, L);

            dp[i][1] = min((i - L - 1) + dp[L][0], (i - L - 1) + dp[L][1]);
            // dp[i][1] = min(dp[i][0], (i - L) + min(dp[L][1], dp[L][1]));
        }

        dbg(mid, dp);

        if(dp[n - 1][0] <= m || dp[n - 1][1] <= m){
            ans = min(ans, mid);
            r = mid - 1;
        }
        else{
            l = mid + 1;
        }
    }

    cout << ans << "\n";
}
