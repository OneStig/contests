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

char ask(int i, int& x) {
    cout << "? " << i << endl;
    char c;
    cin >> c;

    if (c == '<') {
        x--;
    }
    else if (c == '>') {
        x++;
    }

    return c;
}

void solve() {
    int n, x;
    cin >> n >> x;

    vector<int> ans(n);
    // first lets find 1 and n so we can manipulate x
    int onep{1}, np{1};

    for (int i = 1; i <= n; i++) {
        char c = ask(i);
        if (c == '<') {
            onep = i;

            while (c == '<') {
                c = ask(i);
            }
        }
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
