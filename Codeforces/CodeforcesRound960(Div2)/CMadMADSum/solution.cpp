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
        int sum{};
        vector<int> a(n);
        for (int& x : a) {
            cin >> x;
            sum += x;
        }

        int big{};
        map<int, int> f;
        vector<int> b(n);
        for (int i = 0; i < n; i++) {
            if (++f[a[i]] == 2 && a[i] > big) {
                big = a[i];
            }

            b[i] = big;
            sum += big;
        }

        big = 0;
        f = map<int, int>();
        for (int i = 0; i < n; i++) {
            if (++f[b[i]] == 2 && b[i] > big) {
                big = b[i];
            }

            b[i] = big;
            sum += big;
        }

        reverse(all(b));

        for (int i = 0; i < n; i++) {
            sum += i * b[i];
        }

        cout << sum << '\n';
    }
}
