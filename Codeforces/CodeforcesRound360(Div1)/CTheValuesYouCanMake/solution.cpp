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

const int MAX_N = 501;

bool dp[MAX_N][MAX_N][MAX_N];

uci main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int n, cost;
    cin >> n >> cost;

    vector<int> c(n);

    for (int& x : c) cin >> x;

    dp[0][0][0] = 1;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= cost; j++) {
            for (int k = 0; k <= cost; k++) {
                if (dp[i][j][k]) {
                    if (j + c[i] < MAX_N) {
                        dp[i + 1][j + c[i]][k] = 1;
                        if (k + c[i] < MAX_N) {
                            dp[i + 1][j + c[i]][k + c[i]] = 1;
                        }
                    }
                    dp[i + 1][j][k] = 1;
                }
            }
        }
    }

    vector<int> ans;

    for (int i = 0; i <= cost; i++) {
        if (dp[n][cost][i]) {
            ans.push_back(i);
        }
    }

    cout << sz(ans) << '\n';

    for (int& x : ans) {
        cout << x << ' ';
    }

    cout << '\n';
}
