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

uci main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t;
    cin >> t;

    while (t--) {
        int n, k;
        string s;
        cin >> n >> k >> s;

        bool flip = k % 2;

        vector<int> ans(n);

        for (int i = 0; i < n; i++) {
            if (flip) {
                s[i] = (s[i] == '1' ? '0' : '1');
            }

            if (k > 0 && s[i] == '0') {
                s[i] = '1';
                k--;
                ans[i]++;
            }
        }

        if (k > 0) {
            ans[n - 1] += k;
            if (k % 2) {
                s[n - 1] = (s[n - 1] == '1' ? '0' : '1');
            }
        }

        cout << s << '\n';

        for (int& x : ans) {
            cout << x << ' ';
        }

        cout << '\n';
    }
}
