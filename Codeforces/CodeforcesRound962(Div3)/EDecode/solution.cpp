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

const int MOD = 1e9 + 7;

uci main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t;
    cin >> t;

    while (t--) {
        string s;
        cin >> s;

        int n = sz(s);
        unordered_map<int, vector<int>> levels;

        levels[0].push_back(0);
        int cur{};
        for (int i = 0; i < n; i++) {
            if (s[i] == '1') {
                cur++;
            }
            else {
                cur--;
            }
            levels[cur].push_back(i + 1);
        }

        int ans{};

        for (const auto [_, cur] : levels) {
            // prefixes of possible rightbounds
            int k = sz(cur);
            vector<int> pfx(k);
            pfx[k - 1] = n - cur[k - 1] + 1;

            for (int i = k - 2; i >= 0; i--) {
                pfx[i] = n - cur[i] + 1 + pfx[i + 1];
            }

            for (int i = 0; i < k - 1; i++) {
                int possib = (cur[i] + 1) * pfx[i + 1];
                ans += possib;
                ans %= MOD;
            }
        }

        cout << ans << '\n';
    }
}
