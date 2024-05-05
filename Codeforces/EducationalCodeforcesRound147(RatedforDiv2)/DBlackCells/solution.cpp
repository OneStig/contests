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

void solve() {
    int n, k;
    cin >> n >> k;

    vector<array<int, 2>> ranges(n);

    for (int i = 0; i < n; i++) {
        cin >> ranges[i][0];
    }

    for (int i = 0; i < n; i++) {
        cin >> ranges[i][1];
    }

    int skip{}, sum{}, ans{LLONG_MAX};
    
    int rhs{};
    vector<int> skiprhs;

    for (int i = 0; i < ranges.size(); i++) {
        int len = ranges[i][1] - ranges[i][0] + 1;

        if (len == 1) {
            skip++;
            skiprhs.push_back(ranges[i][0]);
        }
        else {
            sum += len;
            rhs = ranges[i][1];
        }

        if (sum >= k) {
            int curans = rhs - (sum - k) + 2 * (i + 1 - skip);
            ans = min(ans, curans);
            break;
        }
        else if (sum + skip >= k) {
            int need = k - sum;
            int curans = max(rhs, skiprhs[need - 1]) + 2 * (i + 1 - skip + need);
            ans = min(ans, curans);
        }
    }

    cout << (ans == LLONG_MAX ? -1 : ans) << '\n';
}

uci main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int tc;
    cin >> tc;

    while (tc--) {
        dbg(tc);
        solve();
    }
}
