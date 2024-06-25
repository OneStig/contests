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
    string s;
    cin >> s;
    int n = sz(s);

    Tree st(n + 1);
    st.update(0, 0);
    vector<int> level(n + 1);
    int cur{};

    for (int i = 0; i < n; i++) {
        cur += (s[i] == '(' ? 1 : -1);
        level[i + 1] = cur;
        st.update(i + 1, cur);
    }

    vector<int> last(n + 1, -1);
    last[0] = 0;
    vector<int> dp(n);
    int ans{};

    for (int r = 1; r <= n; r++) {
        if (last[level[r]] != -1) {
            int l = last[level[r]];

            if (st.query(l, r) <= 2 * level[r]) {
                dp[r] = dp[l] + 1;
                ans += dp[r];
            }
        }
        last[level[r]] = r;
    }

    cout << ans << '\n';
}

uci main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int t;
    cin >> t;

    while (t--) {
        solve();
    }
}
