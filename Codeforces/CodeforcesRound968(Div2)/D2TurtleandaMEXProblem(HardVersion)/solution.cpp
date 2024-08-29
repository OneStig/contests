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

void dfs(int x, map<int, int>& best, map<int, vector<int>>& adj) {
    int res = x;
    for (int y : adj[x]) {
        if (best[y] == 0) {
            dfs(y, best, adj);
        }

        res = max(res, best[y]);
    }

    best[x] = res;
}

uci main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;

        map<int, vector<int>> adj;

        int cap = 0;

        int defans = 0;

        for (int i = 0; i < n; i++) {
            int l;
            cin >> l;
            set<int> a;
            while (l--) {
                int x;
                cin >> x;
                a.insert(x);
            }

            int first = -1, second;
            for (int i = 0; 1; i++) {
                if (a.find(i) == a.end()) {
                    if (first == -1) {
                        first = i;
                    }
                    else {
                        second = i;
                        break;
                    }
                }
            }

            adj[first].push_back(second);
            defans = max(defans, first);
            cap = max(cap, second);
        }

        map<int, int> best;

        for (auto& [x, y] : adj) {
            if (best[x] == 0) {
                dfs(x, best, adj);
            }

            if (sz(y) > 1) {
                defans = max(defans, best[x]);
            }
        }

        int ans = 0;
        for (int i = 0; i <= min(cap, m); i++) {
            int cur = max(i, max(best[i], defans));
            ans += cur;
        }

        if (m > cap) {
            ans += m * (m + 1) / 2 - cap * (cap + 1) / 2;
        }

        cout << ans << '\n';
    }
}
