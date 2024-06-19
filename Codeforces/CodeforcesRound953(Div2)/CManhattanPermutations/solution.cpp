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
    int n, k;
    cin >> n >> k;

    if (k % 2) {
        cout << "No\n";
        return;
    }

    vector<int> a(n);
    iota(all(a), 1);

    int l = 0, r = n - 1;
    while (r - l > 0 && k > 0) {
        int mxdiff = 2 * (a[r] - a[l]);
        if (k >= mxdiff) {
            k -= mxdiff;
            swap(a[l], a[r]);
            l++;
            r--;
        }
        else {
            for (int i = l; k > 0; i++, k -= 2) {
                swap(a[i], a[i + 1]);
            }
        }
    }

    if (k > 0) {
        cout << "No\n";
    }
    else {
        cout << "Yes\n";
        for (int& x : a) {
            cout << x << ' ';
        }
        cout << '\n';
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

// 1 2 3 4 5
// 2 3 4 5 1 -> 8
// 3 2 4 5 1 -> 8
// 3 4 2 5 1 -> 10
// 3 4 5 2 1 -> 12
// 4 3 5 2 1 -> 12
// 4 5 3 2 1 -> 12
