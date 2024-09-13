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

    string s;
    int n;
    cin >> n >> s;
    int mx = pow(2, n);
    int ones{};

    for (char c : s) {
        ones += c == '1';
    }

    // if there is just one 1, only 1 fails.
    // if two 1s, 2->1, 4->3 : 4->2
    // if three 1s, 2->1, 4->3, 6->5, 8->7 : 4->2, 8->6 : 8->4

    int bot = pow(2, ones), top = pow(2, n - ones);
    for (int i = bot; i <= mx - top + 1; i++) {
        cout << i << ' ';
    }
    cout << '\n';
}
