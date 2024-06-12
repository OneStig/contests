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

int query(int i) {
    cout << "? " << i << endl;
    int r;
    cin >> r;
    return r;
}

void solve() {
    int n, k;
    cin >> n >> k;

    int ans{};

    int i = 1;
    for (; n - i + 1 >= 2 * k; i += k) {
        ans ^= query(i);
    }

    if (n - i + 1 == k) {
        ans ^= query(i);
    }
    else {
        // then split the remaining chunk into some parts
        int mid = (n - i + 1 - k) / 2;
        ans ^= query(i) ^ query(i + mid) ^ query(i + 2 * mid);
    }
    cout << "! " << ans << endl;
}

uci main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }
}
