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

#define vi vector<int>

int iv = 0;
int f(int a, int b) { return a + b; } // commutative

struct ST {
  vector<int> s; int n;
  ST(int n = 0) : s(2*n, iv), n(n) {}
  void update(int i, int v) { // a[i] = v
    for (s[i += n] = v; i /= 2;)
      s[i] = f(s[i * 2], s[i * 2 + 1]);
  }
  int query(int b, int e) { // query [b, e)
    int r = iv;
    for (b += n, e += n; b < e; b /= 2, e /= 2) {
      if (b % 2) r = f(r, s[b++]);
      if (e % 2) r = f(s[--e], r);
    }
    return r;
  }
};

const int inf = 1e9;

struct Node {
	Node *l = 0, *r = 0;
	int lo, hi, mset = inf, madd = 0, val = inf;
	Node(int lo,int hi):lo(lo),hi(hi){} // Large interval of -inf
	Node(vi& v, int lo, int hi) : lo(lo), hi(hi) {
		if (lo + 1 < hi) {
			int mid = lo + (hi - lo)/2;
			l = new Node(v, lo, mid); r = new Node(v, mid, hi);
			val = min(l->val, r->val);
		}
		else val = v[lo];
	}
	int query(int L, int R) {
        if (R <= lo || hi <= L) {
            return inf;
        }
		if (L <= lo && hi <= R) return val;
		push();
		return min(l->query(L, R), r->query(L, R));
	}
	void set(int L, int R, int x) {
		if (R <= lo || hi <= L) return;
		if (L <= lo && hi <= R) mset = val = x, madd = 0;
		else {
			push(), l->set(L, R, x), r->set(L, R, x);
			val = min(l->val, r->val);
		}
	}
	void add(int L, int R, int x) {
		if (R <= lo || hi <= L) return;
		if (L <= lo && hi <= R) {
			if (mset != inf) mset += x;
			else madd += x;
			val += x;
		}
		else {
			push(), l->add(L, R, x), r->add(L, R, x);
			val = min(l->val, r->val);
		}
	}
	void push() {
		if (!l) {
			int mid = lo + (hi - lo)/2;
			l = new Node(lo, mid); r = new Node(mid, hi);
		}
		if (mset != inf)
			l->set(lo,hi,mset), r->set(lo,hi,mset), mset = inf;
		else if (madd)
			l->add(lo,hi,madd), r->add(lo,hi,madd), madd = 0;
	}
};

uci main() {
    cin.tie(0)->sync_with_stdio(0);

    int n, l, k;
    cin >> n >> l >> k;
    l--;

    map<int, int> hc;
    set<int> unique;
    ve<int> h(n);

    for (int& x : h) {
        cin >> x;
        unique.insert(x);
    }

    for (int someh : unique) {
        hc[someh] = sz(hc);
    }

    ve<ve<int>> ak(k + 1, ve<int>(sz(hc) + 1, inf));
    ve<Node *> stk(k + 1);

    for (int i = 0; i <= k; i++) {
        stk[i] = new Node(ak[i], 0, sz(hc) + 1);
    }

    ve<ve<int>> dp(n, ve<int>(k + 1, inf));

    dp[l][1] = 0;

    auto upd = [&](int somek, int height, int cost) {
        height = hc[height];
        if (cost < stk[somek]->query(height, height + 1)) {
            stk[somek]->set(height, height + 1, cost);
        }
    };

    auto get = [&](int somek, int height) -> int {
        height = hc[height];
        return stk[somek]->query(0, height);
    };

    dbg(hc);

    upd(1, h[l], 0);

    for (int i = l + 1; i < n; i++) {
        for (int K = 1; K <= k; K++) {
            dbg(i, K, h[i]);
            // delete i
            // dp[i][K] = dp[i - 1][K] + 1;

            // dbg(dp[i][K]);

            // dont delete
            dp[i][K] = min(dp[i][K], get(K - 1, h[i]));

            dbg(get(K - 1, h[i]));
            dbg(dp[i][K]);

            upd(K, h[i], dp[i][K]);
        }

        for (int K = 1; K <= k; K++) {
            stk[K]->add(0, hc[h[i]], 1);
        }
    }

    dbg(dp);

    int ans = inf;

    ST dpst(sz(hc) + 1);
    
    for (int i = n - 1; i >= l; i--) {
        int curcost = dp[i][k] + dpst.query(hc[h[i]] + 1, sz(hc));
        ans = min(ans, curcost);
        dpst.update(hc[h[i]], 1 + dpst.query(hc[h[i]], hc[h[i]] + 1));
    }

    if (ans == inf) {
        ans = -1;
    }
    else {
        for (int j = 0; j < l; j++) {
            if (h[j] >= h[l]) {
                ans++;
            }
        }
    }

    cout << ans << "\n";
}
