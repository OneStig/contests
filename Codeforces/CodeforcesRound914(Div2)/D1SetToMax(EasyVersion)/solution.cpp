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

struct MXTree {
	typedef int T;
	static constexpr T unit = INT_MIN;
	T f(T a, T b) { return max(a, b); } // (any associative fn)
	vector<T> s; int n;
	MXTree(int n = 0, T def = unit) : s(2*n, def), n(n) {}
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

struct MNTree {
	typedef int T;
	static constexpr T unit = INT_MAX;
	T f(T a, T b) { return min(a, b); } // (any associative fn)
	vector<T> s; int n;
	MNTree(int n = 0, T def = unit) : s(2*n, def), n(n) {}
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

uci main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n), b(n);
        MXTree at(n);
        MNTree bt(n);

        for (int i = 0; i < n; i++) {
            cin >> a[i];
            at.update(i, a[i]);
        }

        for (int i = 0; i < n; i++) {
            cin >> b[i];
            bt.update(i, b[i]);
        }

        vector<bool> ans(n);

        vector<int> seen(n + 1, -1);

        for (int i = 0; i < n; i++) {
            if (a[i] > b[i]) break;
            if (a[i] == b[i]) ans[i] = 1;
            if (b[i] > a[i] && seen[b[i]] != -1 && at.query(seen[b[i]], i) <= b[i] && bt.query(seen[b[i]] + 1, i) >= b[i]) {
                ans[i] = 1;
            }

            seen[a[i]] = i;
        }

        seen = vector<int>(n + 1, -1);
        for (int i = n - 1; i >= 0; i--) {
            if (b[i] > a[i] && seen[b[i]] != -1 && at.query(i, seen[b[i]]) <= b[i] && bt.query(i, seen[b[i]] + 1) >= b[i]) {
                ans[i] = 1;
            }

            seen[a[i]] = i;
        }

        bool good = 1;
        for (bool b : ans) {
            good &= b;
        }

        cout << (good ? "YES" : "NO") << '\n';
    }
}
