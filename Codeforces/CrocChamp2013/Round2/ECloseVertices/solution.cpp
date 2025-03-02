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

#define ll long long

struct FT {
	vector<ll> s;
	FT(int n) : s(n) {}
	void update(int i, ll x) { // a[i] += x
		for (; i < sz(s); i |= i + 1) s[i] += x;
	}
	ll query(int i) { // sum of values in [0, i)
		ll res = 0;
		for (; i > 0; i &= i - 1) res += s[i-1];
		return res;
	}
	int lower_bound(ll x) { // min i st sum of [0, i] >= x
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

const int MAX_N = 1e5 + 1;

int n, l, w;

bool rem[MAX_N];
int sub[MAX_N];

ve<pii> adj[MAX_N];
ve<int> cent[MAX_N];
unordered_set<int> subtr[MAX_N];

FT ft(MAX_N);

int dfs_s(int c, int p = -1) {
    sub[c] = 1;
    for (auto [ch, _] : adj[c]) {
        if (ch == p || rem[ch]) continue;
        sub[c] += dfs_s( ch, c);
    }

    return sub[c];
}

int get_c(int c, int n, int p = -1) {
    for (auto [ch, _] : adj[c]) {
        if (ch == p || rem[ch]) continue;
        if (sub[ch] * 2 > n) return get_c(ch, n, c);
    }

    return c;
}

int build(int c = 0) {
    int cen = get_c(c, dfs_s(c));
    // dbg(cen);
    rem[cen] = 1;
    for (auto [ch, _] : adj[cen]) {
        if (!rem[ch]) {
            cent[cen].push_back(build(ch));
        }
    }

    return cen;
}

int path[MAX_N], weight[MAX_N];

void dfs2(int st, int x, int ply = 0, int totw = 0, int p = -1) {
    unordered_set<int>& tovis = subtr[st];
    path[x] = ply;
    weight[x] = totw;

    for (auto [ch, edgew] : adj[x]) {
        if (ch != p && tovis.count(ch)) {
            dfs2(st, ch, ply + 1, totw + edgew, x);
        }
    }
}

void dfs1(int x) {
    subtr[x].insert(x);

    for (int cent_ch : cent[x]) {
        dfs1(cent_ch);
        subtr[x].insert(all(subtr[cent_ch]));
    }
}

int compute(unordered_set<int>& touse) {
    int res = 0;

    ve<int> todo; // negative if query value

    for (int x : touse) {
        todo.push_back(x);
        todo.push_back(-x);
    }

    // Sort by weight
    sort(all(todo), [&](const int& a, const int& b) {
        int aweight = a < 0 ? w - weight[-a] : weight[a];
        int bweight = b < 0 ? w - weight[-b] : weight[b];

        if (aweight == bweight) {
            return a > b; // queries (negative) of the same weight should go after
        }

        return aweight < bweight;
    });

    ve<int> toundo;

    for (int x : todo) {
        if (x < 0) {
            // query
            x = -x;
            int querypath = l - path[x] + 1;
            res += ft.query(querypath);
        }
        else {
            // insert
            int pathlen = path[x];
            ft.update(pathlen, 1);
            toundo.push_back(pathlen);
        }
    }

    // remove all the double self counted things
    for (int x : touse) {
        if (2 * weight[x] <= w && 2 * path[x] <= l) {
            res--;
        }
    }

    // fix the bit
    for (int undo : toundo) {
        ft.update(undo, -1);
    }

    return res;
}

int solve(int x) {
    dfs2(x, x);

    int sum = compute(subtr[x]);

    for (int& ch : cent[x]) {
        sum -= compute(subtr[ch]);
    }

    for (int& ch : cent[x]) {
        sum += solve(ch);
    }

    return sum;
}

uci main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> n >> l >> w;

    for (int i = 2; i <= n; i++) {
        int pi, wi;
        cin >> pi >> wi;
        adj[i].push_back({pi, wi});
        adj[pi].push_back({i, wi});
    }

    int root = build(1);

    // get path(u, p), weight(u, p).
    dfs1(root);

    int ans = solve(root) / 2;
    cout << ans << '\n';
}
