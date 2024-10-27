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

int n, m;
const int INF = 1e12;

uci main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;

    vector<vector<int>> g(n, vector<int>(m));

    vector<int> st;

    map<int, vector<int>> d1, d2;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> g[i][j];
            if (g[i][j] != -1) {
                st.push_back(g[i][j]);
                d1[i + j].push_back(g[i][j]);
                d2[n - i - 1 + j].push_back(g[i][j]);
            }
        }
    }

    sort(all(st));

    auto calc = [&](auto start, auto end) -> int {
        int prev{}, curans{};
        int last = 0;
        for (auto it = start; it != end; it++) {
            const auto& [_, nums] = *it;
            set<int> need;
            for (int i = last; i < last + sz(nums); i++) {
                need.insert(st[i]);
            }

            for (auto& x : nums) {
                if (!need.contains(x)) {
                    curans++;
                }
            }

            last += sz(nums);
        }

        return curans;
    };

    int ans = min({
        calc(d1.begin(), d1.end()),
        calc(d1.rbegin(), d1.rend()),
        calc(d2.begin(), d2.end()),
        calc(d2.rbegin(), d2.rend()),
    });

    cout << ans << '\n';
}
