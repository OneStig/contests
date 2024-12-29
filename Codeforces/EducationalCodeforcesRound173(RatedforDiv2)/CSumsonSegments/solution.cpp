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

const int INF = 1e10;

uci main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        int split = -1;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            if (a[i] != -1 && a[i] != 1) {
                split = i;
            }
        }

        vector<int> lmin(n, INF), lmax(n, -INF), rmin(n, INF), rmax(n, -INF);
        lmin[0] = lmax[0] = a[0];
        for (int i = 1; i < n; i++) {
            lmin[i] = min(lmin[i - 1] + a[i], a[i]);
            lmax[i] = max(lmax[i - 1] + a[i], a[i]);
        }

        rmin[n - 1] = rmax[n - 1] = a[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            rmin[i] = min(rmin[i + 1] + a[i], a[i]);
            rmax[i] = max(rmax[i + 1] + a[i], a[i]);
        }
    
        set<int> ans;
        int mn = 0, mx = 0;
        for (int i = 0; i < split; i++) {
            mn = min(mn, lmin[i]);
            mx = max(mx, lmax[i]);
        }

        for (int i = n - 1; i > split; i--) {
            mn = min(mn, rmin[i]);
            mx = max(mx, rmax[i]);
        }

        for (int i = mn; i <= mx; i++) {
            ans.insert(i);
        }
    
        if (split != -1) {
            mn = mx = a[split];
            if (split != 0) {
                mn += min(0ll, lmin[split - 1]);
                mx += max(0ll, lmax[split - 1]);
            }

            if (split != n - 1) {
                mn += min(0ll, rmin[split + 1]);
                mx += max(0ll, rmax[split + 1]);
            }

            for (int i = mn; i <= mx; i++) {
                ans.insert(i);
            }
        }

        cout << sz(ans) << '\n';
        for (int x : ans) {
            cout << x << ' ';
        }
        cout << '\n';
    }
}
