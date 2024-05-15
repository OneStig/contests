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

#define ll long long
typedef int uci;
#define int long long
#define ld long double
#define sz(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()

const int FAIL = 1e17;

int dfs(int x, vector<uci>& color, vector<vector<int>>& adj) {
    int cursum = color[x];

    bool fail = 0;
    for (int& nb : adj[x]) {
        if (color[nb] == 0) {
            color[nb] = -color[x];
            int child = dfs(nb, color, adj);

            if (child == FAIL) {
                fail = 1;
            }
            cursum += child;
        }
        else if (color[nb] == color[x]) {
            fail = 1;
        }
    }

    return (fail ? FAIL : cursum);
}

uci main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n;
    cin >> n;

    vector<array<int, 3>> disks(n);

    for (int i = 0; i < n; i++) {
        cin >> disks[i][0] >> disks[i][1] >> disks[i][2];
    }

    vector<vector<int>> adj(n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int dx = disks[i][0] - disks[j][0];
            int dy = disks[i][1] - disks[j][1];
            int dist = dx * dx + dy * dy;
            int act = (disks[i][2] + disks[j][2]);
            act *= act;

            if (dist == act) {
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }

    vector<uci> color(n);

    bool ans = 0;
    for (int i = 0; i < n; i++) {
        if (!color[i]) {
            color[i] = 1;
            int cur = dfs(i, color, adj);

            if (cur != 0 && cur != FAIL) {
                ans = 1;
                break;
            }
        }
    }

    cout << (ans ? "YES" : "NO") << '\n';
}
