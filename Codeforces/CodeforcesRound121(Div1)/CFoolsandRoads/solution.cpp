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

const int B = 20;

vector<int> depth;
vector<array<int, B>> lift;
vector<int> parent;
vector<int> paths;

void dfs(int x, int p, vector<vector<int>>& adj) {
	parent[x] = p;
	lift[x][0] = p;
	depth[x] = depth[p] + 1;

	for (int i = 1; i < B; i++) {
		lift[x][i] = lift[lift[x][i - 1]][i - 1];
	}

	for (int nb : adj[x]) {
		if (nb != p) {
			dfs(nb, x, adj);
		}
	}
}

int anc(int u, int v) {
	if (depth[u] > depth[v]) {
		swap(u, v);
	}

	int diff = depth[v] - depth[u];

	for (int i = 0; i < B; i++) {
		if (diff == 0) {
			break;
		}

		if (diff % 2) {
			v = lift[v][i];
		}

		diff /= 2;
	}

	if (u == v) {
		return u;
	}

	for (int i = B - 1; i >= 0; i--) {
		if (lift[u][i] != lift[v][i]) {
			u = lift[u][i];
			v = lift[v][i];
		}
	}

	return parent[u];
}

void dfsans(int x, int p, vector<vector<int>>& adj, vector<int>& ans) {
	int cur = paths[x];

	for (int nb : adj[x]) {
		if (nb != p) {
			dfsans(nb, x, adj, ans);
			cur += ans[nb];
		}
	}

	ans[x] = cur;
}

uci main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n;
    cin >> n;

	vector<vector<int>> adj(n + 1);
	lift.resize(n + 1);
	depth.resize(n + 1);
	parent.resize(n + 1);

	vector<array<int, 2>> roads;

	for (int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;

		adj[u].push_back(v);
		adj[v].push_back(u);

		roads.push_back({u, v});
	}

	parent[1] = 1;
	depth[1] = 0;
	dfs(1, 1, adj);

	paths.resize(n + 1);

	int k;
	cin >> k;

	while (k--) {
		int a, b;
		cin >> a >> b;

		int ancestor = anc(a, b);

		paths[ancestor] -= 2;
		paths[a]++;
		paths[b]++;
	}

	vector<int> ans(n + 1);

	dfsans(1, 1, adj, ans);

	for (auto road : roads) {
		if (parent[road[0]] == road[1]) {
			cout << ans[road[0]] << ' ';
		}
		else {
			cout << ans[road[1]] << ' ';
		}
	}

	cout << '\n';
}
