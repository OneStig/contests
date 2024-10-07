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

typedef int uci;
#define int long long
#define ld long double
#define sz(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()

const int inf = 1e9;
struct Node {
	Node *l = 0, *r = 0;
	int lo, hi, mset = inf, madd = 0, val = -inf;
	Node(int lo,int hi):lo(lo),hi(hi){} // Large interval of -inf
	Node(vector<int>& v, int lo, int hi) : lo(lo), hi(hi) {
		if (lo + 1 < hi) {
			int mid = lo + (hi - lo)/2;
			l = new Node(v, lo, mid); r = new Node(v, mid, hi);
			val = max(l->val, r->val);
		}
		else val = v[lo];
	}
	int query(int L, int R) {
		if (R <= lo || hi <= L) return -inf;
		if (L <= lo && hi <= R) return val;
		push();
		return max(l->query(L, R), r->query(L, R));
	}
	void set(int L, int R, int x) {
		if (R <= lo || hi <= L) return;
		if (L <= lo && hi <= R) mset = val = x, madd = 0;
		else {
			push(), l->set(L, R, x), r->set(L, R, x);
			val = max(l->val, r->val);
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
			val = max(l->val, r->val);
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

void solve() {
    int n, m, q;
    cin >> n >> m >> q;

    vector<int> a(n), b(m), at(n + 1);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        at[a[i]] = i;
    }

    vector<set<int>> loc(n + 1);
    for (int i = 0; i < m; i++) {
        cin >> b[i];
        loc[b[i]].insert(i);
    }

    vector<int> v(m);
    Node* tr = new Node(v, 0, sz(v));

    set<int> gone;
    for (int i = 0; i < m; i++) {
        tr->set(i, i + 1, at[b[i]] - sz(gone));
        gone.insert(b[i]);
    }

    cout << (tr->query(0, m) > 0 ? "TIDAK" : "YA") << '\n';

    while (q--) {
        int i, rep;
        cin >> i >> rep;
        i--;
        // corresponds to: b[i] = rep

        if (b[i] == rep) {
            cout << (tr->query(0, m) > 0 ? "TIDAK" : "YA") << '\n';
            continue;
        }

        tr->add(i, i + 1, at[rep] - at[b[i]]);
        // removing b[i], replacing it with rep
        if (*loc[b[i]].begin() == i) {
            auto it = loc[b[i]].upper_bound(i);
            int until;

            if (it == loc[b[i]].end()) {
                until = m;
            }
            else {
                until = *it + 1;
            }

            tr->add(i + 1, until, 1);
        }
        loc[b[i]].erase(i);

        if (loc[rep].empty() || i < *loc[rep].begin()) {
            auto it = loc[rep].upper_bound(i);
            int until;

            if (it == loc[rep].end()) {
                until = m;
            }
            else {
                until = *it + 1;
            }

            tr->add(i + 1, until, -1);
        }

        loc[rep].insert(i);
        b[i] = rep;

        // dbg(tr->query(0, m));
        cout << (tr->query(0, m) > 0 ? "TIDAK" : "YA") << '\n';
    }
}

uci main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }
}
