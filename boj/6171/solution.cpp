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

const int INF = 1e15;

uci main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    vector<array<int, 2>> land(n);

    for (auto& x : land) {
        cin >> x[0] >> x[1];
    }

    sort(all(land));
    vector<array<int, 2>> plots;

    int mx_width{};

    for (int i = n - 1; i >= 0; i--) {
        if (land[i][1] <= mx_width) continue;
        mx_width = land[i][1];
        plots.push_back(land[i]);
    }

    reverse(all(plots));

    n = plots.size();

    vector<int> dp(n, INF);
    vector<int> lb = {0}, lbi = {0};
    dp[0] = plots[0][0] * plots[0][1];

    for (int i = 1; i < n; i++) {
        // new line: dp[i - 1] + plots[i][1] * x

        int cur;
        while (!lb.empty()) {
            int p = lbi.back();
            int a = dp[i - 1] - (p == 0 ? 0 : dp[p - 1]);
            int b = plots[p][1] - plots[i][1];
            cur = (a + b - 1) / b;

            if (cur > lb.back()) {
                break;
            }

            lb.pop_back();
            lbi.pop_back();
        }

        lb.push_back(cur);
        lbi.push_back(i);

        auto it = upper_bound(all(lb), plots[i][0]);
        int eq = it - lb.begin();
        eq = lbi[eq - 1];

        dp[i] = plots[i][0] * plots[eq][1] + (eq == 0 ? 0 : dp[eq - 1]);
    }

    cout << dp[n - 1] << '\n';
}
