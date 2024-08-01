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

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int& x : a) cin >> x;
        int q;
        string s;
        cin >> s >> q;

        array<int, 2> xo = {0, 0};
        for (int i = 0; i < n; i++) {
            xo[s[i] == '1'] ^= a[i];

            if (i != 0) {
                a[i] ^= a[i - 1];
            }
        }

        while (q--) {
            int p;
            cin >> p;

            if (p == 1) {
                int l, r;
                cin >> l >> r;

                int seg = a[r - 1];
                if (l != 1) {
                    seg ^= a[l - 2];
                }

                xo[0] ^= seg;
                xo[1] ^= seg;
            }
            else {
                int g;
                cin >> g;

                cout << xo[g] << ' ';
            }
        }

        cout << '\n';
    }
}
