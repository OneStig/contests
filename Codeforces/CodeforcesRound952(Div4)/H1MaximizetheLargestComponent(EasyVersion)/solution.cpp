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

#define vi vector<long long>

struct UF {
	vi e;
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

    vector<vector<bool>> grid(n, vector<bool>(m));

    UF dsu(n * m);

    int ans{};

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;

        for (int j = 0; j < m; j++) {
            if (s[j] == '#') {
                grid[i][j] = 1;

                if (i != 0 && grid[i - 1][j]) {
                    dsu.join((i - 1) * m + j, i * m + j);
                }

                if (j != 0 && grid[i][j - 1]) {
                    dsu.join(i * m + j, i * m + j - 1);
                }
                ans = max(ans, dsu.size(i * m + j));
            }

        }
    }

    // check rows

    for (int r = 0; r < n; r++) {
        int cur{};
        set<int> seen;

        for (int c = 0; c < m; c++) {
            if (grid[r][c]) {
                int par = dsu.find(r * m + c);
                if (!seen.contains(par)) {
                    seen.insert(par);
                    cur += dsu.size(par);
                }
            }
            else {
                cur++;

                if (r != 0 && grid[r - 1][c]) {
                    int par = dsu.find((r - 1) * m + c);
                    if (!seen.contains(par)) {
                        seen.insert(par);
                        cur += dsu.size(par);
                    }
                }

                if (r != n - 1 && grid[r + 1][c]) {
                    int par = dsu.find((r + 1) * m + c);
                    if (!seen.contains(par)) {
                        seen.insert(par);
                        cur += dsu.size(par);
                    }
                }

            }
        }

        ans = max(ans, cur);
    }

    for (int c = 0; c < m; c++) {
        int cur{};
        set<int> seen;

        for (int r = 0; r < n; r++) {
            if (grid[r][c]) {
                int par = dsu.find(r * m + c);
                if (!seen.contains(par)) {
                    seen.insert(par);
                    cur += dsu.size(par);
                }
            }
            else {
                cur++;

                if (c != 0 && grid[r][c - 1]) {
                    int par = dsu.find(r * m + c - 1);
                    if (!seen.contains(par)) {
                        seen.insert(par);
                        cur += dsu.size(par);
                    }
                }

                if (c != m - 1 && grid[r][c + 1]) {
                    int par = dsu.find(r * m + c + 1);
                    if (!seen.contains(par)) {
                        seen.insert(par);
                        cur += dsu.size(par);
                    }
                }

            }
        }

        ans = max(ans, cur);
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
