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

        vector<vector<int>> adj(n + 1);
        vector<int> color(n + 1, -1);

        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        bool alice = 0;
        color[1] = 0;
        queue<int> bfs;
        vector<int> ones, twos;
        bfs.push(1);
        ones.push_back(1);
        while (sz(bfs)) {
            int cur = bfs.front();
            bfs.pop();

            for (int& nb : adj[cur]) {
                if (color[nb] == -1) {
                    color[nb] = 1 - color[cur];
                    bfs.push(nb);
                    if (color[nb] == 0) {
                        ones.push_back(nb);
                    }
                    else {
                        twos.push_back(nb);
                    }
                }
                else if (color[nb] == color[cur]) {
                    alice = 1;
                    break;
                }
            }

            if (alice) break;
        }

        if (alice) {
            cout << "Alice" << endl;
            for (int i = 0; i < n; i++) {
                cout << "1 2" << endl;
                int _;
                cin >> _ >> _;
            }
            continue;
        }

        cout << "Bob" << endl;

        for (int i = 0; i < n; i++) {
            int a, b;
            cin >> a >> b;
            if (a > b) swap(a, b);

            if (a == 1) {
                if (sz(ones)) {
                    cout << ones.back() << " 1" << endl;
                    ones.pop_back();
                }
                else {
                    cout << twos.back() << ' ' << b << endl;
                    twos.pop_back();
                }
            }
            else {
                if (sz(twos)) {
                    cout << twos.back() << " 2" << endl;
                    twos.pop_back();
                }
                else {
                    cout << ones.back() << " 3" << endl;
                    ones.pop_back();
                }
            }
        }
    }
}
