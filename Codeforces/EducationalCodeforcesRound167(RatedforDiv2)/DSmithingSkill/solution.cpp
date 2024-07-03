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

const int MAX_A = 1e6 + 1;

uci main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n, m;
    cin >> n >> m;
    vector<int> c(m);

    vector<array<int, 2>> tools(n);
    for (auto& x : tools) {
        cin >> x[0];
    }

    for (auto& x : tools) {
        cin >> x[1];
        x[1] = x[0] - x[1];
    }

    for (int& x : c) cin >> x;

    sort(all(tools));

    vector<array<int, 2>> rem;
    int mn{MAX_A};
    for (int i = 0; i < sz(tools); i++) {
        if (tools[i][1] < mn) {
            rem.push_back(tools[i]);
            mn = tools[i][1];
        }
    }

    n = sz(rem);
    reverse(all(rem));

    vector<int> dp(rem[0][0] + 1);
    int take = sz(rem);
    for (int i = 1; i <= rem[0][0]; i++) {
        while (take > 0 && rem[take - 1][0] <= i) {
            take--;
        }

        if (take != sz(rem)) {
            dp[i] = 2 + dp[i - rem[take][1]];
        }
    }

    int ans{};
    for (int x : c) {
        if (x < sz(dp)) {
            ans += dp[x];
        }
        else {
            int fit = (x - rem[0][0]) / rem[0][1] + 1;
            ans += 2 * fit + dp[x - rem[0][1] * fit];
        }
    }

    cout << ans << '\n';
}
