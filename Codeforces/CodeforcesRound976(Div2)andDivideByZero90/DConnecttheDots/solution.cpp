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

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<vector<int>>> pfx(11, vector<vector<int>>(10, vector<int>(2 * n + 2)));

    while (m--) {
        int a, d, k;
        cin >> a >> d >> k;

        pfx[d][a % d][2 * a]++;
        pfx[d][a % d][2 * (a + k * d) + 1]--;
    }

    UF g(n + 1);
    for (int d = 1; d <= 10; d++) {
        for (int o = 0; o < d; o++) {
            for (int i = 1; i <= 2 * n; i++) {
                pfx[d][o][i] += pfx[d][o][i - 1];
            }

            for (int i = 1; i <= n; i++) {
                if (i % d != o) continue;
                int last = i - d;
                if (last >= 1 && pfx[d][o][2 * i - 1]) {
                    g.join(last, i);
                }
            }
        }
    }

    set<int> comp;
    for (int i = 1; i <= n; i++) {
        comp.insert(g.find(i));
    }

    cout << sz(comp) << '\n';
}

uci main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }
}
