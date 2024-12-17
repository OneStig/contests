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

uci main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    vector<string> g;
    string s;
    while (cin >> s) {
        g.emplace_back(s);
    }

    int r = sz(g);
    int c = sz(g[0]);

    dbg(r, c);

    vector<int> dr = {-1, 1, 0, 0};
    vector<int> dc = {0, 0, -1, 1};
    vector<vector<set<int>>> dp(r, vector<set<int>>(c));
    vector<vector<set<vector<int>>>> dp2(r, vector<set<vector<int>>>(c));


    for (char i = '9'; i >= '0'; i--) {
        dbg(i);
        for (int j = 0; j < r; j++) {
            for (int k = 0; k < c; k++) {
                if (g[j][k] == i) {
                    if (i == '9') {
                        dp[j][k].insert(j * r + k);
                        vector<int> cur = {j * r + k};
                        dp2[j][k].insert(cur);
                    }
                    else {
                        for (int nb = 0; nb < 4; nb++) {
                            if (j + dr[nb] < 0 || j + dr[nb] >= r || k + dc[nb] < 0 || k + dc[nb] >= c) {
                                continue;
                            }

                            if (g[j + dr[nb]][k + dc[nb]] == i + 1) {
                                for (int x : dp[j + dr[nb]][k + dc[nb]]) {
                                    dp[j][k].insert(x);
                                }

                                for (auto y : dp2[j + dr[nb]][k + dc[nb]]) {
                                    y.push_back(j * r + k);
                                    dp2[j][k].insert(y);
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    int ans = 0;
    set<vector<int>> ans2;

    for (int j = 0; j < r; j++) {
        for (int k = 0; k < c; k++) {
            if (g[j][k] == '0') {
                ans += sz(dp[j][k]);

                for (auto x : dp2[j][k]) {
                    ans2.insert(x);
                }
            }
        }
    }

    cout << ans << '\n';
    cout << sz(ans2) << '\n';

}
