#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 200005;
int n;
vector<pair<int,int>> adj[MAXN];
bool removed[MAXN];
int subtree_size[MAXN];
int par_arr[MAXN];
ll answer = 0;

void compute_subtree_size(int root) {
    stack<int> stk;
    vector<int> order;
    par_arr[root] = -1;
    stk.push(root);
    while (!stk.empty()) {
        int v = stk.top(); stk.pop();
        order.push_back(v);
        subtree_size[v] = 1;
        for (auto& [u, w] : adj[v])
            if (u != par_arr[v] && !removed[u]) {
                par_arr[u] = v;
                stk.push(u);
            }
    }
    for (int i = (int)order.size()-1; i >= 0; i--) {
        int v = order[i];
        if (par_arr[v] != -1)
            subtree_size[par_arr[v]] += subtree_size[v];
    }
}

int get_centroid(int root, int tree_size) {
    int v = root;
    int p = -1;
    while (true) {
        bool found = false;
        for (auto& [u, w] : adj[v])
            if (u != p && !removed[u] && subtree_size[u] > tree_size / 2) {
                p = v;
                v = u;
                found = true;
                break;
            }
        if (!found) return v;
    }
}

struct NodeInfo { ll d, m, val; };

void gather(int root, int root_par, ll init_dist, ll init_max, vector<NodeInfo>& nodes) {
    stack<tuple<int,int,ll,ll>> stk;
    stk.push({root, root_par, init_dist, init_max});
    while (!stk.empty()) {
        auto [v, p, dist, maxe] = stk.top(); stk.pop();
        nodes.push_back({dist, maxe, 2*maxe - dist});
        for (auto& [u, w] : adj[v])
            if (u != p && !removed[u])
                stk.push({u, v, dist + w, max(maxe, (ll)w)});
    }
}

ll count_pairs(vector<NodeInfo>& nodes) {
    int sz = nodes.size();
    if (sz <= 1) return 0;
    
    vector<ll> d_sorted(sz);
    for (int i = 0; i < sz; i++) d_sorted[i] = nodes[i].d;
    sort(d_sorted.begin(), d_sorted.end());
    
    ll term1 = 0;
    for (int i = 0; i < sz; i++) {
        ll v = nodes[i].val;
        term1 += (int)(lower_bound(d_sorted.begin(), d_sorted.end(), v) - d_sorted.begin());
    }
    
    vector<ll> all_vals(sz);
    for (int i = 0; i < sz; i++) all_vals[i] = nodes[i].val;
    sort(all_vals.begin(), all_vals.end());
    all_vals.erase(unique(all_vals.begin(), all_vals.end()), all_vals.end());
    int V = all_vals.size();
    
    vector<int> order(sz);
    iota(order.begin(), order.end(), 0);
    sort(order.begin(), order.end(), [&](int a, int b) {
        return nodes[a].m > nodes[b].m;
    });
    
    vector<int> bit(V+1, 0);
    auto bit_update = [&](int i, int delta) { for (i++; i <= V; i += i&(-i)) bit[i] += delta; };
    auto bit_query = [&](int i) -> int { int s=0; for (i++; i>0; i-=i&(-i)) s+=bit[i]; return s; };
    auto bit_range = [&](int l, int r) -> int { return l>r ? 0 : bit_query(r) - (l>0 ? bit_query(l-1) : 0); };
    
    ll term2 = 0;
    int i = 0;
    while (i < sz) {
        int j = i;
        while (j < sz && nodes[order[j]].m == nodes[order[i]].m) j++;
        
        for (int k = i; k < j; k++) {
            int a = order[k];
            ll da = nodes[a].d;
            int idx = (int)(upper_bound(all_vals.begin(), all_vals.end(), da) - all_vals.begin());
            if (idx < V) term2 += bit_range(idx, V-1);
        }
        
        for (int k = i; k < j; k++) {
            int a = order[k];
            int idx = (int)(lower_bound(all_vals.begin(), all_vals.end(), nodes[a].val) - all_vals.begin());
            bit_update(idx, 1);
        }
        i = j;
    }
    
    return term1 + term2;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 0; i < n-1; i++) {
        int u, v, s;
        cin >> u >> v >> s;
        adj[u].push_back({v, s});
        adj[v].push_back({u, s});
    }
    
    stack<int> todo;
    todo.push(1);
    
    while (!todo.empty()) {
        int v = todo.top(); todo.pop();
        
        compute_subtree_size(v);
        int sz = subtree_size[v];
        int c = get_centroid(v, sz);
        removed[c] = true;
        
        vector<NodeInfo> all_nodes;
        all_nodes.push_back({0, 0, 0});
        
        vector<vector<NodeInfo>> subtree_nodes;
        for (auto& [u, w] : adj[c]) {
            if (!removed[u]) {
                vector<NodeInfo> sub;
                gather(u, c, w, w, sub);
                subtree_nodes.push_back(sub);
                for (auto& ni : sub) all_nodes.push_back(ni);
            }
        }
        
        ll total = count_pairs(all_nodes);
        for (auto& sub : subtree_nodes)
            total -= count_pairs(sub);
        
        answer += total / 2;
        
        for (auto& [u, w] : adj[c])
            if (!removed[u])
                todo.push(u);
    }
    
    cout << answer << "\n";
    return 0;
}
