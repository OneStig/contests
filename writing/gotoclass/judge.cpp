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
bool removed_node[MAXN];
int sub_sz[MAXN];

void get_sizes(int u, int p) {
    sub_sz[u] = 1;
    for (auto& edge : adj[u]) {
        int v = edge.first;
        if (v != p && !removed_node[v]) {
            get_sizes(v, u);
            sub_sz[u] += sub_sz[v];
        }
    }
}

int get_centroid(int u, int p, int total) {
    for (auto& edge : adj[u]) {
        int v = edge.first;
        if (v != p && !removed_node[v] && sub_sz[v] > total / 2) {
            return get_centroid(v, u, total);
        }
    }
    return u;
}

void get_paths(int u, int p, int cur_max, int cur_sum, ve<pii>& paths) {
    paths.push_back({cur_max, cur_sum});
    for (auto& edge : adj[u]) {
        int v = edge.first;
        int w = edge.second;
        if (v != p && !removed_node[v]) {
            get_paths(v, u, max(cur_max, w), cur_sum + w, paths);
        }
    }
}

int count_pairs(ve<pii>& paths) {
    int pairs = 0;
    
    sort(paths.begin(), paths.end());
    
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
    int centroid = get_centroid(u, -1, sub_sz[u]);
    
    removed_node[centroid] = true;
    int local_bottlenecks = 0;
    
    ve<pii> all_paths;
    all_paths.push_back({0, 0});
    
    for (auto& edge : adj[centroid]) {
        int v = edge.first;
        int w = edge.second;
        if (!removed_node[v]) {
            ve<pii> sub_paths;
            get_paths(v, centroid, w, w, sub_paths);
            
            // subtract overcounted pairs that reside entirely in the same subtree
            local_bottlenecks -= count_pairs(sub_paths);
            
            for (auto& p : sub_paths) {
                all_paths.push_back(p);
            }
        }
    }
    
    // add all valid pairs going through the centroid
    local_bottlenecks += count_pairs(all_paths);
    
    // process subtrees and accumulate their results
    for (auto& edge : adj[centroid]) {
        int v = edge.first;
        if (!removed_node[v]) {
            local_bottlenecks += solve_centroid(v);
        }
    }
    
    return local_bottlenecks;
}

uci main() {
    cin.tie(0)->sync_with_stdio(0);

    int n;
    cin >> n;

    for (int i = 0; i < n - 1; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    cout << solve_centroid(1) << '\n';
}
