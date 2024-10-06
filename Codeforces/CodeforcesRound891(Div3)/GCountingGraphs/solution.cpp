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

const int MOD = 998244353;

struct UF {
	vector<int> e;
	UF(int n) : e(n, -1) {}
	bool sameSet(int a, int b) { return find(a) == find(b); }
	int size(int x) { return -e[find(x)]; }
	int find(int x) { return e[x] < 0 ? x : e[x] = find(e[x]); }
	bool join(int a, int b) {
		a = find(a), b = find(b);
		if (a == b) return false;
		if (e[a] > e[b]) swap(a, b);
		e[a] += e[b]; e[b] = a;
		return true;
	}
};

int binpow(int a, int n) { // a^n
    if (n == 0) return 1;
    if (n % 2 == 0) {
        return binpow(a * a % MOD, n / 2);
    }
    else {
        return a * binpow(a, n - 1) % MOD;
    }
}

uci main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t;
    cin >> t;

    while (t--) {
        int n, s;
        cin >> n >> s;
        vector<array<int, 3>> edges(n - 1);
        for (auto& x : edges) {
            cin >> x[1] >> x[2] >> x[0];
        }

        sort(all(edges));

        UF g(n + 1);

        int ans = 1;
        for (auto& e : edges) {
            int left = g.size(e[1]), right = g.size(e[2]);
            ans = ans * binpow(s - e[0] + 1, left * right - 1) % MOD;
            g.join(e[1], e[2]);
        }

        cout << ans << '\n';
    }
}
