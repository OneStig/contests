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

    vector<int> fib(46);
    fib[0] = 1;
    fib[1] = 1;
    for (int i = 2; i < sz(fib); i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }

    int t;
    cin >> t;

    while (t--) {
        int n, x, y;
        cin >> n >> x >> y;

        string ans = "YES";
        int w = fib[n], h = fib[n + 1];

        while (w != 1 && h != 1) {
            if (h > w) {
                if (y <= h - w) {
                    h -= w;
                }
                else if (y > w) {
                    h -= w;
                    y -= w;
                }
                else {
                    ans = "NO";
                    break;
                }
            }
            else {
                if (x <= w - h) {
                    w -= h;
                }
                else if (x > h) {
                    w -= h;
                    x -= h;
                }
                else {
                    ans = "NO";
                    break;
                }
            }
        }

        cout << ans << '\n';
    }
}
