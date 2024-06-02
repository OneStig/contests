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
    int n, s1, s2;
    cin >> n >> s1 >> s2;

    vector<pair<int, int>> freq(n);

    for (int i = 1; i <= n; i++) {
        int r;
        cin >> r;

        freq[i - 1] = {r, i};
    }

    sort(all(freq));

    int at = s1, bt = s2;
    vector<int> a, b;

    for (int i = n - 1; i >= 0; i--) {
        if (at < bt) {
            a.push_back(freq[i].second);
            at += s1;
        }
        else {
            b.push_back(freq[i].second);
            bt += s2;
        }
    }

    cout << sz(a);
    for (int& x : a) cout << ' ' << x;
    cout << '\n' << sz(b);
    for (int& x : b) cout << ' ' << x;
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
