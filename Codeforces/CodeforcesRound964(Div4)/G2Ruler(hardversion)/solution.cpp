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

int ask(int a, int b) {
    cout << "? " << a << ' ' << b << endl;
    int x;
    cin >> x;
    return x;
}

void solve() {
    // idea: 3^7 > 1000, so we can use 2 dimensions to ternary search for x

    int l = 2, r = 999;
    while (l != r) {
        int mid1 = l + (r - l) / 3;
        int mid2 = r - (r - l) / 3;

        int actual = ask(mid1, mid2);

        if (actual == mid1 * mid2) {
            l = mid2 + 1;
        }
        else if (actual == mid1 * (mid2 + 1)) {
            l = mid1 + 1;
            r = mid2;
        }
        else {
            r = mid1;
        }
    }

    cout << "! " << l << endl;
}

uci main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }
}
