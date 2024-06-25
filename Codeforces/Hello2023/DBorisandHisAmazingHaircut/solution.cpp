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

struct Tree {
	typedef int T;
	static constexpr T unit = INT_MIN;
	T f(T a, T b) { return max(a, b); } // (any associative fn)
	vector<T> s; int n;
	Tree(int n = 0, T def = unit) : s(2*n, def), n(n) {}
	void update(int pos, T val) {
		for (s[pos += n] = val; pos /= 2;)
			s[pos] = f(s[pos * 2], s[pos * 2 + 1]);
	}
	T query(int b, int e) { // query [b, e)
		T ra = unit, rb = unit;
		for (b += n, e += n; b < e; b /= 2, e /= 2) {
			if (b % 2) ra = f(ra, s[b++]);
			if (e % 2) rb = f(s[--e], rb);
		}
		return f(ra, rb);
	}
};

void solve() {
    int n;
    cin >> n;

    vector<int> a(n), b(n);

    for (int& x : a) cin >> x;
    for (int& x : b) cin >> x;

    int m;
    cin >> m;

    map<int, int> razors;

    while (m--) {
        int x;
        cin >> x;

        razors[x]++;
    }

    bool yes = 1;

    map<int, vector<int>> seg;

    Tree st(n);

    for (int i = 0; i < n; i++) {

        st.update(i, b[i]);
        if (a[i] < b[i]) {
            yes = 0;
            break;
        }

        if (a[i] > b[i]) {
            seg[b[i]].push_back(i);
        }
    }

    if (yes) {
        for (const auto& [h, pts] : seg) {
            int need = sz(pts);

            for (int i = 1; i < sz(pts); i++) {
                if (st.query(pts[i - 1], pts[i] + 1) <= h) {
                    need--;
                }
            }

            if (need > razors[h]) {
                yes = 0;
                break;
            }
        }
    }

    cout << (yes ? "YES\n" : "NO\n");
}

uci main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }
}
