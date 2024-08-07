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

void solve() {
    int n, x;
    cin >> n >> x;

    vector<int> p(n + 1);
    set<int> unseen;
    int xpos{};

    for (int i = 1; i <= n; i++) {
        cin >> p[i];

        if (p[i] == x) {
            xpos = i;
        }

        unseen.insert(p[i]);
    }

    int l = 1, r = n + 1;

    while (r - l != 1) {
        int m = (r + l) / 2;
        unseen.erase(p[m]);

        if (p[m] <= x) {
            l = m;
        }
        else {
            r = m;
        }
    }

    if (l == xpos) {
        cout << 0 << '\n';
        return;
    }

    // swap xpos and l
    swap(p[xpos], p[l]);

    if (unseen.contains(x) || p[l] <= x) {
        cout << "1\n" << xpos << ' ' << l << '\n';
    }
    else {
        cout << "2\n" << xpos << ' ' << l << '\n';
        cout << "aaaa\n";
    }
}

uci main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }
}
