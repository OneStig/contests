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

        vector<int> a(n), b(n);
        for (int& x : a) cin >> x;
        for (int& x : b) cin >> x;

        int as{}, bs{};

        int inc{}, dec{};

        for (int i = 0; i < n; i++) {
            if (a[i] > b[i]) {
                as += a[i];
            }
            else if (b[i] > a[i]) {
                bs += b[i];
            }
            else if (a[i] == 1) {
                inc++;
            }
            else if (a[i] == -1) {
                dec++;
            }
        }

        if (as > bs) {
            swap(as, bs);
        }

        int diff = min(bs - as, inc);
        inc -= diff;
        as += diff;

        as += inc / 2;
        bs += (inc + 1) / 2;

        diff = min(bs - as, dec);
        dec -= diff;
        bs -= diff;
        as -= dec / 2;
        bs -= (dec + 1) / 2;

        cout << min(as, bs) << '\n';
    }
}
