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
    vector<int> a(n);
    int tot{};
    for (int& x : a) {
        cin >> x;
        tot += x;
    }

    if (tot % 3 != 0) {
        cout << 0 << '\n';
        return 0;
    }

    int th = tot / 3;
    int ans{}, cur{}, seen{};
    for (int i = 0; i < n - 1; i++) {
        int x = a[i];
        cur += x;
        if (cur == 2 * th) {
            ans += seen;
        }
        if (cur == th) {
            seen++;
        }
    }

    cout << ans << '\n';
}
