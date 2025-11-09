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

struct DSU {
	vi e; void init(int N) { e = vi(N,-1); }
	int get(int x) { return e[x] < 0 ? x : e[x] = get(e[x]); }
	bool sameSet(int a, int b) { return get(a) == get(b); }
	int size(int x) { return -e[get(x)]; }
	bool unite(int x, int y) { // union by size
		x = get(x), y = get(y); if (x == y) return 0;
		if (e[x] > e[y]) swap(x,y);
		e[x] += e[y]; e[y] = x; return 1;
	}
};

ld dist(ld x1, ld y1, ld x2, ld y2) {
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

uci main() {
    cin.tie(0)->sync_with_stdio(0);

    int n, e, p;
    cin >> n >> e >> p;

    ve<pair<ld, ld>> house(n);
    for (auto& x : house) {
        cin >> x.first >> x.second;
    }
    
    DSU dsu;
    dsu.init(n);

    int comps = n;

    while (p--) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        comps -= dsu.unite(u, v);
    }

    for (int i = 1; i < e; i++) {
        comps -= dsu.unite(i - 1, i);
    }

    typedef pair<ld, pair<int, int>> edge;

    priority_queue<edge, vector<edge>, greater<edge>> pq;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            pq.push({dist(house[i].first, house[i].second, house[j].first, house[j].second), {i, j}});
        }
    }

    ld ans = 0;

    while (comps > 1) {
        auto best = pq.top();
        pq.pop();
    
        bool att = dsu.unite(best.second.first, best.second.second);
        
        if (att) {
            comps--;
            ans += best.first;
        }
    }

    cout << fixed << setprecision(8) << ans << '\n';
}
