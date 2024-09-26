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

const int MOD = 998244353;
const int MAX_N = 2e5;

uci main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    vector<int> fact(MAX_N + 1);

    int cur = 1;
    for (int i = 1; i <= MAX_N; i++) {
        cur *= i;
        cur %= MOD;
        fact[i] = cur;
    }

    int t;
    cin >> t;

    while (t--) {
        string s;
        cin >> s;
        int n = sz(s);
        vector<int> block;

        char last = 'x';
        for (int i = 0; i < n; i++) {
            if (s[i] != last) {
                block.push_back(0);
            }
            block.back()++;
            last = s[i];
        }

        int fans = n - sz(block);
        int ans = max(fact[fans], 1ll);

        for (int& x : block) {
            ans *= x;
            ans %= MOD;
        }

        cout << fans << ' ' << ans << '\n';
    }
}
