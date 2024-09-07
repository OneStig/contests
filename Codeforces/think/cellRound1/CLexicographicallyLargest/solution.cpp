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
    int n;
    cin >> n;

    set<int> used, unused;
    unused.insert(-1);

    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        x += i;

        int orig = x;

        if (used.contains(x)) {
            x = *(prev(unused.upper_bound(x)));
            if (orig - x <= i - 1) {
                used.insert(x);
                unused.erase(x);
                if (x > 2 && !used.contains(x - 1)) {
                    unused.insert(x - 1);
                }
            }
        }
        else {
            used.insert(x);

            if (unused.contains(x)) {
                unused.erase(x);
            }

            if (x > 2 && !used.contains(x - 1)) {
                unused.insert(x - 1);
            }
        }
    }

    for (auto it = used.rbegin(); it != used.rend(); it++) {
        cout << *it << ' ';
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

// First ensure maximum possible, then most unique elements
// what if there are multiple ways to make it?
