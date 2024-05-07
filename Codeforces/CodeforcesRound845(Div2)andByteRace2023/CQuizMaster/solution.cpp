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

const int MAX_M = 1e5;
const int INF = 1e9;

uci main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    vector<vector<int>> facts(MAX_M + 1);
    for (int i = 1; i <= MAX_M; i++) {
        for (int j = i; j <= MAX_M; j += i) {
            facts[j].push_back(i);
        }
    }

    int tc;
    cin >> tc;

    while (tc--) {
        int n, m;
        cin >> n >> m;

        vector<int> a(n);

        for (int& x : a) {
            cin >> x;
        }

        sort(all(a));

        vector<int> freq(m + 1);
        int count = 0;

        int ans = INF;

        int l = 0;
        for (int r = 0; r < n; r++) {
            for (int& f : facts[a[r]]) {
                if (f > m) break;

                if (!freq[f]++) {
                    count++;
                }
            }
            dbg(l, r, count);

            while (count == m) {
                ans = min(ans, a[r] - a[l]);

                for (int& f : facts[a[l]]) {
                    if (f > m) break;

                    if (!--freq[f]) {
                        count--;
                    }
                }

                l++;
            }
        }

        cout << (ans == INF ? -1 : ans) << '\n';
    }
}
