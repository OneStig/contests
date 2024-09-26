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
        int n, k;
        cin >> n >> k;

        vector<int> c(n);
        for (int& x : c) cin >> x;

        for (int i = 0; i < k; i++) {
            int p;
            cin >> p;
            c[p - 1] = 0;
        }

        vector<vector<int>> to(n);
        vector<vector<int>> from(n);
        vector<int> rem(n);
        queue<int> todo;
        set<int> vis;

        for (int i = 0; i < n; i++) {
            int m;
            cin >> m;
            rem[i] = m;
            if (c[i] == 0 || m == 0)  {
                vis.insert(i);
                todo.push(i);
            }
            for (int j = 0; j < m; j++) {
                int dep;
                cin >> dep;
                dep--;
                to[dep].push_back(i);
                from[i].push_back(dep);
            }
        }

        while (!todo.empty()) {
            int cur = todo.front();
            todo.pop();
            if (sz(from[cur])) {
                int cost{};
                for (int& dep : from[cur]) {
                    cost += c[dep];
                }

                c[cur] = min(c[cur], cost);
            }

            for (int& req : to[cur]) {
                if (--rem[req] == 0 && !vis.contains(req)) {
                    todo.push(req);
                }
            }
        }

        for (int& x : c) cout << x << ' ';
        cout << '\n';
    }
}
