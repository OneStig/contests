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

#define ll long long
typedef int uci;
#define int long long
#define ld long double
#define sz(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()

const int INF = 1e15;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n), cold(k), hot(k);

    for (int& x : a) {
        cin >> x;
        x--;
    }

    for (int& x : cold) cin >> x;
    for (int& x : hot) cin >> x;

    vector<int> dp(k + 1, INF);

    // 0 -> k - 1, nothing on alternate cpu for k
    dp[k] = 0;
    int total{}, lastsw{}; // when prev is the same, just add the hot

    int prev{k};

    for (int i = 0; i < n; i++) {
        int cur = a[i];

        if (cur == prev) {
            total += hot[cur];
            continue;
        }

        // if not same we must take cold, except for if cur is on alternate cpu
        total += cold[cur];

        // if the alternate cpu contains cur, we move prev to alternate cpu
        // which is dp of cur + hot[cur] - cold of cur since we added it total
        // take min of which one we want to switch from
        dp[prev] = min(lastsw, dp[cur] + hot[cur] - cold[cur]);
        lastsw = dp[prev];

        prev = cur;
    }

    int ans{INF};

    for (int& x : dp) {
        ans = min(ans, x);
    }

    cout << ans + total << '\n';
}

uci main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }
}
