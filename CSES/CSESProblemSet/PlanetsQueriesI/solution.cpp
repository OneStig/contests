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
 
const int MAX_N = 2e5;
const int MAX_B = 18;

int lift[MAX_N][MAX_B];
 
uci main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
    int n, q;
    cin >> n >> q;
 
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
 
        lift[i][0] = t - 1;
    }
 
    for (int b = 1; b < MAX_B; b++) {
        for (int i = 0; i < n; i++) {
            lift[i][b] = lift[lift[i][b - 1]][b - 1];
        }
    }

    vector<bool> vis(n);
    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            int cur = i;

            while (i)
        }
    }

    // find cycles
    vector<int> depth(n)
 
    while (q--) {
        uci x, k;
        cin >> x >> k;
        x--;
 
        for (int i = 0; i < bits; i++) {
            if (k % 2) {
                x = lift[x][i];
            }
 
            k /= 2;
        }

        cout << x + 1 << '\n';
    }
}
