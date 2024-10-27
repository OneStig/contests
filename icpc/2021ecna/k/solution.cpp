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

    int h, w;
    cin >> h >> w;
    int n{};
    vector<vector<int>> g(h, vector<int>(w));
    set<int> top, bottom;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cin >> g[i][j];
            n = max(n, g[i][j]);
            if (i == 0) {
                top.insert(g[i][j]);
            }

            if (i == h - 1) {
                bottom.insert(g[i][j]);
            }
        }
    }

    vector<set<int>> up(n + 1), down(n + 1);
    for (int i = 1; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (g[i][j] != g[i - 1][j]) {
                up[g[i][j]].insert(g[i - 1][j]);
                down[g[i - 1][j]].insert(g[i][j]);
            }
        }
    }

    int a = *top.begin(), b = *top.rbegin();
    vector<int> adist(n + 1, INF), bdist(n + 1, INF);

    auto bfs = [&](vector<int> start, vector<set<int>>& graph, vector<int>& dist) {
        queue<int> process;
        for (int& x : start) {
            dist[x] = 1;
            process.push(x);
        }

        while (!process.empty()) {
            int cur = process.front();
            process.pop();

            for (int nb : graph[cur]) {
                if (dist[nb] == INF) {
                    dist[nb] = dist[cur] + 1;
                    process.push(nb);
                }
            }
        }
    };

    bfs(vector<int>{a}, down, adist);

    if (a == b) {
        int ans = INF;
        for (int x : bottom) {
            ans = min(ans, adist[x]);
        }

        cout << ans << '\n';
    }
    else {
        bfs(vector<int>{b}, down, bdist);
        vector<int> updist(n + 1, INF);
        vector<int> bstart;
        for (int x : bottom) {
            bstart.push_back(x);
        }
        bfs(bstart, up, updist);

        int ans = INF, mna = INF, mnb = INF;
        for (int x : bottom) {
            mna = min(mna, adist[x]);
            mnb = min(mnb, bdist[x]);
        }

        ans = min(ans, mna + mnb);

        for (int i = 1; i <= n; i++) {
            ans = min(ans, adist[i] + bdist[i] - 2 + updist[i]);
        }

        cout << ans << '\n';
    }
}
