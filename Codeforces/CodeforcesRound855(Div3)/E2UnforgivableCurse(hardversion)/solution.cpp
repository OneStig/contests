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

    int tc;
    cin >> tc;

    while (tc--) {
        int n, k;
        string s, t;
        cin >> n >> k >> s >> t;

        map<int, int> freq;
        for (char c : s) freq[c]++;
        for (char c : t) freq[c]--;

        bool good = 1;
        for (auto [x, y] : freq) {
            if (y != 0) {
                good = 0;
                break;
            }
        }

        if (good) {
            for (int i = min(n - 1, k - 1); i >= max(0ll, n - k); i--) {
                if (s[i] != t[i]) {
                    good = 0;
                    break;
                }
            }
        }

        cout << (good ? "YES" : "NO") << '\n';
    }
}
