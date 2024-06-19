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

const int INF = 1e9;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int& x : a) cin >> x;

    vector<int> pfx(n + 1), sfx(n + 1);

    vector<int> ans(n, INF);

    pfx[1] = a[0];

    vector<int> ldiff(n);
    ldiff[0] = -1;

    for (int i = 1; i < n; i++) {
        if (a[i] != a[i - 1]) {
            ldiff[i] = i - 1;
        }
        else {
            ldiff[i] = ldiff[i - 1];
        }

        pfx[i + 1] = pfx[i] + a[i];

        if (a[i - 1] > a[i]) {
            ans[i] = 1;
            continue;
        }

        int l = 0, r = i - 1;
        while (l <= r) {
            int mid = (l + r) / 2;

            bool good = (pfx[i] - pfx[mid] > a[i]) && (mid == i - 1 || ldiff[i - 1] >= mid);

            if (good) {
                ans[i] = min(ans[i], i - mid);
                l = mid + 1;
            }
            else {
                r = mid - 1;
            }
        }
    }

    sfx[n - 1] = a[n - 1];
    ldiff[n - 1] = n;

    for (int i = n - 2; i >= 0; i--) {
        if (a[i] != a[i + 1]) {
            ldiff[i] = i + 1;
        }
        else {
            ldiff[i] = ldiff[i + 1];
        }

        sfx[i] = sfx[i + 1] + a[i];

        if (a[i + 1] > a[i]) {
            ans[i] = 1;
            continue;
        }

        int l = i + 1, r = n - 1;
        while (l <= r) {
            int mid = (l + r) / 2;

            bool good = (sfx[i + 1] - sfx[mid + 1] > a[i]) && (mid == i + 1 || ldiff[i + 1] <= mid);

            if (good) {
                ans[i] = min(ans[i], mid - i);
                r = mid - 1;
            }
            else {
                l = mid + 1;
            }
        }
    }

    for (int& x : ans) {
        cout << (x == INF ? -1 : x) << ' ';
    }

    cout << '\n';
}


uci main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }
}
