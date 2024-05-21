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

#define pii pair<int, int>

uci main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n, m, k;
    cin >> n >> m >> k;

    // pii for adj to prefer non-augmented edges
    vector<set<pii>> adj(n + 1);
    vector<int> deg(n + 1);

    for (int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;

        adj[a].insert({0, b});
        adj[b].insert({0, a});
        deg[a]++;
        deg[b]++;
    }

    if (k > m) {
        cout << "Impossible\n";
        return 0;
    }

    vector<vector<int>> paths;
    unordered_map<int, unordered_set<int>> extra;

    int lastodd{}, odds{};

    for (int i = 1; i <= n; i++) {
        if (deg[i] % 2) {
            odds++;
        }
    }

    if (k < paths.size()) {
        cout << "Impossible\n";
        return 0;
    }

    // otherwise we need to chunk it into extra pieces
    int extra = k - paths.size();

    cout << "Possible\n";
    for (auto& path : paths) {
        while (extra && path.size() > 2) {
            cout << path.back() << ' ';
            path.pop_back();
            cout << path.back() << '\n';
            extra--;
        }

        for (int& x : path) {
            cout << x << ' ';
        }
        cout << '\n';
    }
}
