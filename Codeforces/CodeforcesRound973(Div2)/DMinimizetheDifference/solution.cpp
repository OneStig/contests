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

const int MAX_A = 1e12;

uci main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int& x : a) cin >> x;

        int truemn = 0, truemx = MAX_A;
        int l = 0, r = a.front();
        while (l <= r) {
            int mn = (l + r) / 2;

            bool good = 1;
            int carry = 0;
            for (int i = 0; i < n; i++) {
                if (a[i] > mn) {
                    carry += a[i] - mn;
                }
                else if (a[i] < mn) {
                    if (carry >= mn - a[i]) {
                        carry -= mn - a[i];
                    }
                    else {
                        good = 0;
                        break;
                    }
                }

            }

            if (good) {
                truemn = max(truemn, mn);
                l = mn + 1;
            }
            else {
                r = mn - 1;
            }
        }

        l = a.back(), r = MAX_A;
        while (l <= r) {
            int mx = (l + r) / 2;

            int carry = 0;
            for (int i = 0; i < n; i++) {
                if (a[i] > mx) {
                    carry += a[i] - mx;
                }
                else {
                    int move = min(carry, mx - a[i]);
                    carry -= move;
                }
            }

            if (carry == 0) {
                truemx = min(truemx, mx);
                r = mx - 1;
            }
            else {
                l = mx + 1;
            }
        }

        cout << truemx - truemn << '\n';
    }
}
