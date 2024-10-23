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

#define pi pair<int, int>

const int INF = 1e12;

int g, k, r;

uci main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> g >> k >> r;

    vector<vector<pair<int, int>>> adj(k + 1);
    vector<array<int, 4>> venues(g);

    for (int i = 0; i < r; i++) {
        int a, b, t;
        cin >> a >> b >> t;
        adj[a].push_back({b, t});
        adj[b].push_back({a, t});
    }

    for (auto& v : venues) {
        // end, start, venue, mcost
        cin >> v[2] >> v[1] >> v[0] >> v[3];
    }

    sort(all(venues));

    vector<vector<int>> bests(k + 1, vector<int>(k + 1, INF));

    for (int s = 1; s <= k; s++) {
        bests[s][s] = 0;
        priority_queue<pi, vector<pi>, greater<pi>> pq;

        pq.push({0, s});
        while (!pq.empty()) {
            auto [dis, cur] = pq.top();
            pq.pop();

            if (dis != bests[s][cur]) continue;

            for (auto& [nb, ew] : adj[cur]) {
                if (dis + ew < bests[s][nb]) {
                    bests[s][nb] = dis + ew;
                    pq.push({bests[s][nb], nb});
                }
            }
        }
    }

    vector<int> ends(g);
    for (int i = 0; i < g; i++) {
        ends[i] = venues[i][0];
    }

    vector<vector<int>> dp(g, vector<int>(k + 1, -INF));

    for (int i = 0; i < g; i++) {
        if (i != 0) {
            dp[i] = dp[i - 1];
        }

        int vert = venues[i][2];
        int mcost = venues[i][3];

        if (bests[1][vert] <= venues[i][1]) {
            dp[i][vert] = max(dp[i][vert], mcost);
        }

        for (int last = 1; last <= k; last++) {
            auto it = upper_bound(all(ends), venues[i][1] - bests[last][vert]);

            if (it != ends.begin()){
                int trans = (it - ends.begin()) - 1;
                // trans should be >= 0
                dp[i][vert] = max(dp[i][vert], dp[trans][last] + mcost);
            }
        }
    }

    int ans{};
    for (int i = 1; i <= k; i++) {
        ans = max(ans, dp[g - 1][i]);
    }

    cout << ans << '\n';
}
