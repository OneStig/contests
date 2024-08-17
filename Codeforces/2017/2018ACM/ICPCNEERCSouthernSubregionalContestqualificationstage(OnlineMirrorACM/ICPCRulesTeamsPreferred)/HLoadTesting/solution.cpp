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
    for (int& x : a) cin >> x;

    vector<array<int, 2> > sfx(n); // sfx cost and individual new
    sfx[n - 1][1] = a[n - 1];
    sfx[n - 1][0] = 0;

    for (int i = n - 2; i >= 0; i--) {
        sfx[i][0] = sfx[i + 1][0];

        if (a[i] <= sfx[i + 1][1]) {
            sfx[i][1] = sfx[i + 1][1] + 1;
            sfx[i][0] += sfx[i + 1][1] + 1 - a[i];
        }
        else {
            sfx[i][1] = a[i];
        }
    }

    int ans = sfx[0][0], pfx = 0;

    for (int i = 1; i < n; i++) {
        int cur = sfx[i][0] + pfx;
        if (a[i - 1] + 1> sfx[i][1]) {
            cur += a[i - 1] + 1 - sfx[i][1];
        }

        ans = min(ans, cur);
        int newa = max(a[i - 1] + 1, a[i]);
        pfx += newa - a[i];
        a[i] = newa;
    }

    cout << ans << '\n';
}
