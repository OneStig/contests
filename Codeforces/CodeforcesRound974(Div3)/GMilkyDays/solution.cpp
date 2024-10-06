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

const int INF = 1e9;

uci main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t;
    cin >> t;

    while (t--) {
        int n, m, k;
        cin >> n >> m >> k;
        vector<int> a(n), d(n);

        for (int i = 0; i < n; i++) {
            cin >> d[i] >> a[i];
        }

        int ans{};
        vector<pair<int, int>> stk;
        for (int i = 0; i < n; i++) {
            int day = d[i], need = m, next = i == n - 1 ? INF : d[i + 1];

            stk.emplace_back(d[i], a[i]);
            while (!stk.empty() && stk.back().first > day - k) {
                if (day == next) break;
                if (stk.back().second < need) {
                    need -= stk.back().second;
                    stk.pop_back();
                }
                else {
                    ans++;
                    stk.back().second -= need;
                    int boost = min({day + stk.back().second / m, stk.back().first + k - 1, next - 1});
                    stk.back().second -= (boost - day) * m;
                    ans += boost - day;
                    need = m;
                    day = boost + 1;
                }
            }
        }

        cout << ans << '\n';
    }
}
