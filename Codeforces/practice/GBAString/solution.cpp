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
    int n, k, x;
    cin >> n >> k >> x;
    string s;
    cin >> s;

    vector<int> bmax;
    vector<char> print;

    int streak = 0;
    for (int i = 0; i < sz(s); i++) {
        if (s[i] == 'a') {
            if (streak) {
                bmax.push_back(streak * k + 1);
                streak = 0;
                print.push_back('*');
            }
            print.push_back('a');
        }
        else {
            streak++;
        }
    }

    if (streak) {
        bmax.push_back(streak * k + 1);
        print.push_back('*');
    }

    dbg(bmax);

    vector<int> ans(sz(bmax));

    x--;
    for (int i = sz(bmax) - 1; i >= 0; i--) {
        ans[i] = x % bmax[i];
        x /= bmax[i];
    }

    dbg(ans);
    dbg(print);

    int nxt = 0;
    for (char c : print) {
        if (c == '*') {
            while (ans[nxt]--) {
                cout << 'b';
            }
            nxt++;
        }
        else {
            cout << c;
        }
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
