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

    int n;
    cin >> n;

    vector<int> c(2 * n);
    for (int& x : c) cin >> x;

    dbg(c);

    vector<pair<int, int>> chunks;

    int mx{}, chunk{-1};
    for (int i = 0; i < 2 * n; i++) {
        if (c[i] > mx) {
            if (chunk != -1) {
                chunks.push_back({chunk, i});
            }
            chunk = i;
            mx = c[i];
        }
    }

    chunks.push_back({chunk, 2 * n});
    dbg(chunks);

    vector<bool> dp(n + 1);
    vector<int> btrack(n + 1); // backtrack
    dp[0] = 1;

    for (int i = 0; i < sz(chunks); i++) {
        vector<bool> ndp(n + 1);
        for (int j = 0; j <= n; j++) {

        }
    }
}
