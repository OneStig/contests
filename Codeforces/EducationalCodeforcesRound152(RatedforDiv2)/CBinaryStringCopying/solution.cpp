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
        string s;
        int n, m;
        cin >> n >> m >> s;

        bool same = 0;
        set<pair<int, int>> unique;
        vector<int> ones(n), zeros(n);

        for (int i = 0; i < n; i++) {
            if (s[i] == '0') zeros[i] = i;
            else {
                if (i == 0) zeros[i] = -1;
                else zeros[i] = zeros[i - 1];
            }
        }

        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == '1') ones[i] = i;
            else {
                if (i == n - 1) ones[i] = n;
                else ones[i] = ones[i + 1];
            }
        }

        for (int i = 0; i < m; i++) {
            int l, r;
            cin >> l >> r;
            l--, r--;

            if (r == l || ones[l] > r || zeros[r] < l || ones[l] > zeros[r]) {
                same = 1;
            }
            else {
                unique.insert({ones[l], zeros[r]});
            }
        }

        cout << sz(unique) + same << '\n';
    }
}
