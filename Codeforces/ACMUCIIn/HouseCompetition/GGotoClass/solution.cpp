#include <bits/stdc++.h>

using namespace std;

#ifndef ONLINE_JUDGE
#include "cpp-dump/cpp-dump.hpp"
#define dbg(...) cpp_dump(__VA_ARGS__)
#else
#define dbg(...)
#endif

typedef int uci;
#define int long long
#define ld long double
#define ve vector
#define sz(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()
typedef pair<int, int> pii;

// fenwick tree from kactl
// https://github.com/OneStig/catlicku/blob/main/content/data-structures/FenwickTree.h
struct FT {
    ve<int> s;
    FT(int n) : s(n) {}
    void update(int i, int x) { // a[i] += x
        for (; i < sz(s); i |= i + 1) s[i] += x;
    }
    int query(int i) { // sum of values in [0, i)
        int res = 0;
        for (; i > 0; i &= i - 1) res += s[i-1];
        return res;
    }
    int lower_bound(int x) { // min i st sum of [0, i] >= x
        // Returns n if no sum is >= x, or -1 if empty sum is.
        if (x <= 0) return -1;
        int i = 0;
        for (int pw = 1 << 25; pw; pw >>= 1) {
            if (i + pw <= sz(s) && s[i + pw-1] < x)
                i += pw, x -= s[i-1];
        }
        return i;
    }
};

const int MAXN = 2e5 + 5;
ve<pii> adj[MAXN];
bool removed[MAXN];
int subtr_sz[MAXN];

void get_sizes(int u, int p) {
    subtr_sz[u] = 1;
    for (auto& edge : adj[u]) {
        int v = edge.first;
        if (v != p && !removed[v]) {
            get_sizes(v, u);
            subtr_sz[u] += subtr_sz[v];
        }
    }
}

int find_centroid(int u, int p, int total) {
    for (auto& edge : adj[u]) {
        int v = edge.first;
        if (v != p && !removed[v] && subtr_sz[v] > total / 2) {
            return find_centroid(v, u, total);
        }
    }
    return u;
}

void find_paths(int u, int p, int cur_max, int cur_sum, ve<pii>& paths) {
    paths.push_back({cur_max, cur_sum});
    for (auto& edge : adj[u]) {
        int v = edge.first;
        int w = edge.second;
        if (v != p && !removed[v]) {
            find_paths(v, u, max(cur_max, w), cur_sum + w, paths);
        }
    }
}

int count_pairs(ve<pii>& paths) {
    int pairs = 0;
    
    sort(paths.begin(), paths.end());
    
    // we have to coordinate compress unique lengths
    // to utilize fenwick tree
    ve<int> vals;
    vals.reserve(paths.size() * 2);
    for (auto& p : paths) {
        vals.push_back(p.second);
        vals.push_back(2 * p.first - p.second);
    }
    sort(vals.begin(), vals.end());
    vals.erase(unique(vals.begin(), vals.end()), vals.end());
    
    FT bit(sz(vals));
    
    for (auto& p : paths) {
        int target = 2 * p.first - p.second;
        
        int target_idx = lower_bound(vals.begin(), vals.end(), target) - vals.begin();
        
        pairs += bit.query(target_idx);
        
        int sum_idx = lower_bound(vals.begin(), vals.end(), p.second) - vals.begin();
        bit.update(sum_idx, 1);
    }
    
    return pairs;
}

int solve_centroid(int u) {
    get_sizes(u, -1);
    int centroid = find_centroid(u, -1, subtr_sz[u]);
    
    removed[centroid] = true;
    int bottlenecks = 0;
    
    ve<pii> all_paths;
    all_paths.push_back({0, 0});
    
    for (auto& edge : adj[centroid]) {
        int v = edge.first;
        int w = edge.second;
        if (!removed[v]) {
            ve<pii> sub_paths;
            find_paths(v, centroid, w, w, sub_paths);
            
            // subtract overcounted pairs that reside entirely in the same subtree
            bottlenecks -= count_pairs(sub_paths);
            
            for (auto& p : sub_paths) {
                all_paths.push_back(p);
            }
        }
    }
    
    bottlenecks += count_pairs(all_paths);
    
    for (auto& edge : adj[centroid]) {
        int v = edge.first;
        if (!removed[v]) {
            bottlenecks += solve_centroid(v);
        }
    }
    
    return bottlenecks;
}

uci main() {
    cin.tie(0)->sync_with_stdio(0);

    int n;
    cin >> n;

    for (int i = 1; i < n; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    cout << solve_centroid(1) << '\n';
}

