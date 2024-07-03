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

const int MAX_N = 5e4;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    map<int, int> freq;
    for (int& x : a) {
        cin >> x;
        freq[x]++;
    }

    int ans = 0;

    vector<int> dp(sz(freq) + 1, MAX_N);
    dp[0] = 0;
    int i{};
    for (auto& [c, f] : freq) {
        vector<int> ndp = dp;

        for (int j = 0; j < sz(freq); j++) {
            if (f <= i - j - dp[j]) {
                ndp[j + 1] = min(ndp[j + 1], dp[j] + f);
            }
        }

        dp = ndp;
        i++;
    }

    for (int i = 0; i <= sz(freq); i++) {
        if (dp[i] != MAX_N) {
            ans = i;
        }
    }

    ans = sz(freq) - ans;

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
