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
        if (n == 1) cout << "1\n1\n";
        else if (n == 2) cout << "2\n1 2\n";
        else if (n == 3) cout << "2\n1 2 2\n";
        else if (n == 4) cout << "3\n1 2 2 3\n";
        else if (n == 5) cout << "3\n1 2 2 3 3\n";
        else if (n == 6) cout << "4\n1 2 2 3 3 4\n";
        else {
            cout << "4\n";
            for (int i = 1; i <= n; i++) {
                cout << i % 4 + 1 << ' ';
            }
            cout << '\n';
        }
    }
}
