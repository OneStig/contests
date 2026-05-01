#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 200005;
vector<pair<int, long long>> adj[MAXN];
bool removed_node[MAXN];
int sz[MAXN];
long long total_ans = 0;

// Calculates the size of each subtree to find the centroid
void get_sizes(int u, int p) {
    sz[u] = 1;
    for(auto& edge : adj[u]) {
        int v = edge.first;
        if(v != p && !removed_node[v]) {
            get_sizes(v, u);
            sz[u] += sz[v];
        }
    }
}

// Locates the centroid of the current component
int get_centroid(int u, int p, int total) {
    for(auto& edge : adj[u]) {
        int v = edge.first;
        if(v != p && !removed_node[v]) {
            if(sz[v] * 2 > total) {
                return get_centroid(v, u, total);
            }
        }
    }
    return u;
}

// Collects the maximum edge weight and total distance for all nodes to the centroid
void get_nodes(int u, int p, long long current_max, long long current_dist, vector<pair<long long, long long>>& nodes_list) {
    nodes_list.push_back({current_max, current_dist});
    for(auto& edge : adj[u]) {
        int v = edge.first;
        long long w = edge.second;
        if(v != p && !removed_node[v]) {
            get_nodes(v, u, max(current_max, w), current_dist + w, nodes_list);
        }
    }
}

// Sorts nodes and uses a Fenwick Tree to count valid pairs
long long count_pairs(vector<pair<long long, long long>>& nodes) {
    if(nodes.empty()) return 0;
    
    // Sort primarily by max edge weight
    sort(nodes.begin(), nodes.end(), [](const pair<long long, long long>& a, const pair<long long, long long>& b) {
        return a.first < b.first;
    });

    // Coordinate Compression for the distances
    vector<long long> D;
    D.reserve(nodes.size());
    for (auto& p : nodes) {
        D.push_back(p.second);
    }
    sort(D.begin(), D.end());
    D.erase(unique(D.begin(), D.end()), D.end());

    long long pairs = 0;
    vector<int> bit(D.size() + 2, 0);
    
    auto add = [&](int idx, int val) {
        for (; idx < bit.size(); idx += idx & -idx) bit[idx] += val;
    };
    
    auto query = [&](int idx) {
        int sum = 0;
        for (; idx > 0; idx -= idx & -idx) sum += bit[idx];
        return sum;
    };

    for (auto& p : nodes) {
        long long m = p.first;
        long long d = p.second;
        long long target = 2 * m - d;

        // Query the number of distances strictly less than target
        int count_less = lower_bound(D.begin(), D.end(), target) - D.begin();
        if (count_less > 0) {
            pairs += query(count_less);
        }

        // Insert current distance into the Fenwick Tree
        int pos = lower_bound(D.begin(), D.end(), d) - D.begin() + 1;
        add(pos, 1);
    }

    return pairs;
}

// Main recursive centroid decomposition function
void solve(int u) {
    get_sizes(u, -1);
    int total = sz[u];
    int C = get_centroid(u, -1, total);

    removed_node[C] = true;

    vector<pair<long long, long long>> all_nodes;
    all_nodes.push_back({0, 0}); // Include the centroid itself

    long long ans_C = 0;

    for(auto& edge : adj[C]) {
        int v = edge.first;
        long long w = edge.second;
        if(!removed_node[v]) {
            vector<pair<long long, long long>> subtree_nodes;
            get_nodes(v, C, w, w, subtree_nodes);
            
            // Subtract invalid pairs that don't cross the centroid
            ans_C -= count_pairs(subtree_nodes);
            all_nodes.insert(all_nodes.end(), subtree_nodes.begin(), subtree_nodes.end());
        }
    }

    // Add valid pairs from the entire connected component
    ans_C += count_pairs(all_nodes);
    total_ans += ans_C;

    // Recurse into the independent subtrees
    for(auto& edge : adj[C]) {
        int v = edge.first;
        if(!removed_node[v]) {
            solve(v);
        }
    }
}

int main() {
    // Optimize standard I/O operations for competitive programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    if(!(cin >> n)) return 0;
    
    for(int i = 0; i < n - 1; ++i) {
        int u, v;
        long long s;
        cin >> u >> v >> s;
        adj[u].push_back({v, s});
        adj[v].push_back({u, s});
    }
    
    solve(1);
    cout << total_ans << "\n";
    
    return 0;
}
