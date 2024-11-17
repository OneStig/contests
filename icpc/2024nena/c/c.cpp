#include <bits/stdc++.h>

using namespace std;

typedef int uci;
#define int long long
#define sz(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()

struct Dinic {
	struct Edge {
		int to, rev;
		int c, oc;
		int flow() { return max(oc - c, 0LL); } // if you need flows
	};
	vector<int> lvl, ptr, q;
	vector<vector<Edge>> adj;
	Dinic(int n) : lvl(n), ptr(n), q(n), adj(n) {}
	void addEdge(int a, int b, int c, int rcap = 0) {
		adj[a].push_back({b, sz(adj[b]), c, c});
		adj[b].push_back({a, sz(adj[a]) - 1, rcap, rcap});
	}
	int dfs(int v, int t, int f) {
		if (v == t || !f) return f;
		for (int& i = ptr[v]; i < sz(adj[v]); i++) {
			Edge& e = adj[v][i];
			if (lvl[e.to] == lvl[v] + 1)
				if (int p = dfs(e.to, t, min(f, e.c))) {
					e.c -= p, adj[e.to][e.rev].c += p;
					return p;
				}
		}
		return 0;
	}
	int calc(int s, int t) {
		int flow = 0; q[0] = s;
		for (int L = 0; L < 31; L++) {
		do { // 'int L=30' maybe faster for random data
			lvl = ptr = vector<int>(sz(q));
			int qi = 0, qe = lvl[s] = 1;
			while (qi < qe && !lvl[t]) {
				int v = q[qi++];
				for (Edge e : adj[v])
					if (!lvl[e.to] && e.c >> (30 - L))
						q[qe++] = e.to, lvl[e.to] = lvl[v] + 1;
			}
			while (int p = dfs(s, t, LLONG_MAX)) flow += p;
		} while (lvl[t]);
		}
		return flow;
	}
	bool leftOfMinCut(int a) { return lvl[a] != 0; }
};

uci main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int n, m;
    cin >> n >> m;

    int total{};
    vector<array<int, 3>> edges(m);
    for (auto& e : edges) {
        cin >> e[0] >> e[1] >> e[2];
        total += e[2];
    }

    int l = 0, r = total / n;
    while (l != r) {
        int mid = (l + r + 1) / 2;

        Dinic d(n + m + 2);
        int enode = n + 1;
        for (auto& e : edges) {
            d.addEdge(0, enode, e[2]);
            d.addEdge(enode, e[0], e[2]);
            d.addEdge(enode, e[1], e[2]);
            enode++;
        }

        for (int i = 1; i <= n; i++) {
            d.addEdge(i, n + m + 1, mid);
        }

        int mxflow = d.calc(0, n + m + 1);
        if (mxflow == n * mid) {
            l = mid;
        }
        else {
            r = mid - 1;
        }
    }

    cout << total - n * l << '\n';
}
