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

        vector<int> p(n + 1);
        for (int i = 1; i <= n; i++) cin >> p[i];
        string s;
        cin >> s;

        map<int, int> f;
        for (int i = 1; i <= n; i++) {
            if (!f.contains(i)) {
                int count = s[i - 1] == '0';
                int cur = p[i];
                while (cur != i) {
                    count += s[cur - 1] == '0';
                    cur = p[cur];
                }
                while (!f.contains(cur)) {
                    f[cur] = count;
                    cur = p[cur];
                }
            }

            cout << f[i] << ' ';
        }

        cout << '\n';
    }
}