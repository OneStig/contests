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

void solve() {
    int n, m;
    cin >> n >> m;
    int tot = n + m + 1;

    vector<int> a(tot), b(tot);
    vector<int> prefa(tot), prefb(tot), pfx(tot), sfxa(tot), sfxb(tot);

    for (int& x : a) cin >> x;
    for (int& x : b) cin >> x;

    for (int i = 0; i < tot; i++) {
        prefa[i] = a[i] > b[i];
        prefb[i] = b[i] > a[i];
        pfx[i] = max(a[i], b[i]);
        if (i != 0) {
            prefa[i] += prefa[i - 1];
            prefb[i] += prefb[i - 1];
            pfx[i] += pfx[i - 1];
        }
    }

    sfxa[tot - 1] = a[tot - 1];
    sfxb[tot - 1] = b[tot - 1];

    for (int i = tot - 2; i >= 0; i--) {
        sfxa[i] = a[i] + sfxa[i + 1];
        sfxb[i] = b[i] + sfxb[i + 1];
    }

    for (int omit = 0; omit < tot; omit++) {
        if (n == 0) {
            cout << sfxb[0] - b[omit] << ' ';
            continue;
        }

        if (m == 0) {
            cout << sfxa[0] - a[omit] << ' ';
            continue;
        }

        int l = 0, r = tot - 1;

        while (l != r) {
            int mid = (l + r) / 2;

            int atot = prefa[mid];
            int btot = prefb[mid];

            if (omit <= mid) {
                if (a[omit] > b[omit]) {
                    atot--;
                }
                else {
                    btot--;
                }
            }

            if (atot >= n || btot >= m) {
                r = mid;
            }
            else {
                l = mid + 1;
            }
        }

        int ans = pfx[l];

        int aend = prefa[l];

        if (omit <= l) {
            if (a[omit] > b[omit]) {
                aend--;
            }
        }
        

        if (l < tot - 1) {
            if (aend == n) {
                ans += sfxb[l + 1];
            }
            else {
                ans += sfxa[l + 1];
            }
        }

        if (omit <= l) {
            ans -= max(a[omit], b[omit]);
        }
        else if (aend == n) {
            ans -= b[omit];
        }
        else {
            ans -= a[omit];
        }

        cout << ans << ' ';
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
