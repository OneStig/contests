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

uci main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t;
    cin >> t;

    while (t--) {
        int n, k, q;
        cin >> n >> k >> q;

        vector<int> a(k + 1), b(k + 1);

        for (int i = 1; i <= k; i++) {
            cin >> a[i];
        }

        for (int i = 1; i <= k; i++) {
            cin >> b[i];
        }

        while (q--) {
            int d;
            cin >> d;

            int pos = lower_bound(all(a), d) - a.begin();

            if (a[pos] == d) {
                cout << b[pos] << ' ';
            }
            else {
                int dist = d - a[pos - 1];
                int td = (b[pos] - b[pos - 1]) * dist / (a[pos] - a[pos - 1]);
                int ans = b[pos - 1] + td;
                cout << ans << ' ';
            }
        }

        cout << '\n';
    }
}
