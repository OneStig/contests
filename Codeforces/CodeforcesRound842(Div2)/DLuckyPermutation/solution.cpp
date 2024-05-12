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

struct DSU {
    vector<int> e;

    void init(int n) { e = vector<int>(n, -1); }
    int find(int x) { return (e[x] < 0 ? x : e[x] = find(e[x])); }
    int size(int x) { return -e[find(x)]; }
    bool is_same(int a, int b) { return find(a) == find(b); }
    bool unite(int a, int b) {
        a = find(a), b = find(b);
        if (a == b) return false;
        if (e[a] > e[b]) swap(a, b);
        e[a] += e[b];
        e[b] = a;
        return true;
    }
};

uci main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        int comp = n;
        DSU graph;
        graph.init(n);

        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            x--;

            if (graph.unite(i, x)) {
                comp--;
            }
        }

        int best = n - comp + 1;

        for (int i = 0; i < n - 1; i++) {
            if (graph.is_same(i, i + 1)) {
                best = n - comp - 1;
                break;
            }
        }

        cout << best << '\n';
    }
}
