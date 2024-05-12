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

const int MAX_N = 2e5 + 1;

int n, t;
vector<int> adj[MAX_N];
int first[MAX_N], second[MAX_N];

void dfs(int x, int par) {
    for (int& nb : adj[x]) {
        if (nb == par) continue;

        dfs(nb, x);

        first[x] += !first[nb];
    }
}

void dfsa(int x, int par, int flip) {
    second[x] = first[x] + !flip;

    for (auto& nb : adj[x]) {
        if (nb == par) continue;

        dfsa(nb, x, second[x] - !first[nb]);
    }
}

uci main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> t;

    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1, -1);
    dfsa(1, -1, 1);

    while (t--) {
        int q;
        cin >> q;

        cout << (second[q] ? "Ron" : "Hermione") << '\n';
    }
}
