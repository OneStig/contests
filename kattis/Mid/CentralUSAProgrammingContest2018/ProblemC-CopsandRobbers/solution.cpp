#include <bits/stdc++.h>

using namespace std;

#define ONLINE_JUDGE

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

#define vi vector<int>
#define ll long long

struct Dinic {
	struct Edge {
		int to, rev;
		ll c, oc;
		ll flow() { return max(oc - c, 0LL); } // if you need flows
	};
	vi lvl, ptr, q;
	vector<vector<Edge>> adj;
	Dinic(int n) : lvl(n), ptr(n), q(n), adj(n) {}
	void addEdge(int a, int b, ll c, ll rcap = 0) {
		adj[a].push_back({b, sz(adj[b]), c, c});
		adj[b].push_back({a, sz(adj[a]) - 1, rcap, rcap});
	}
	ll dfs(int v, int t, ll f) {
		if (v == t || !f) return f;
		for (int& i = ptr[v]; i < sz(adj[v]); i++) {
			Edge& e = adj[v][i];
			if (lvl[e.to] == lvl[v] + 1)
				if (ll p = dfs(e.to, t, min(f, e.c))) {
					e.c -= p, adj[e.to][e.rev].c += p;
					return p;
				}
		}
		return 0;
	}
    ll calc(int s, int t) {
        ll flow = 0;
        q[0] = s;
        for (int L = 0; L < 31; L++) {
            do {
                lvl = ptr = vi(sz(q));
                int qi = 0, qe = lvl[s] = 1;
                while (qi < qe && !lvl[t]) {
                    int v = q[qi++];
                    for (Edge e : adj[v])
                        if (!lvl[e.to] && (e.c >> (30 - L)))
                            q[qe++] = e.to, lvl[e.to] = lvl[v] + 1;
                }
                while (ll p = dfs(s, t, LLONG_MAX))
                    flow += p;
            } while (lvl[t]);
        }
        return flow;
    }
    bool leftOfMinCut(int a) { return lvl[a] != 0; }
};

const int INF = 1e12;

uci main() {
    cin.tie(0)->sync_with_stdio(0);

    int n, m, c;
    cin >> m >> n >> c;

    ve<string> grid(n);
    for (auto& row : grid) {
        cin >> row;
    }
    ve<int> costs(c);
    for (int& ci : costs) cin >> ci;

    int mxdir = 31 * 31;
    // cellin = r * m + c
    // cellout = mxdir + r * m + c
    int bnode;
    int sinknode = 2 * mxdir + 1;
    Dinic flow(sinknode + 1);

    for (int row = 0; row < n; row++) {
        for (int col = 0; col < m; col++) {
            int cellin = row * m + col;
            int cellout = mxdir + row * m + col;
            
            int leftin = row * m + col - 1;
            int rightin = row * m + col + 1;
            int topin = (row - 1) * m + col;
            int botin = (row + 1) * m + col;

            if (row == 0 || row == n - 1 || col == 0 || col == m - 1) {
                flow.addEdge(cellout, sinknode, INF);
            }

            if (row != 0) flow.addEdge(cellout, topin, INF);
            if (row != n - 1) flow.addEdge(cellout, botin, INF);
            if (col != 0) flow.addEdge(cellout, leftin, INF);
            if (col != m - 1) flow.addEdge(cellout, rightin, INF);

            int cost;
            if (grid[row][col] == '.') {
                cost = INF;
            }
            else if (grid[row][col] == 'B') {
                cost = INF;
                bnode = cellin;
            }
            else {
                cost = costs[grid[row][col] - 'a'];
            }

            flow.addEdge(cellin, cellout, cost);
        }
    }

    int ans = flow.calc(bnode, sinknode);
    
    if (ans >= INF) {
        ans = -1;
    }
    
    cout << ans << '\n';
}