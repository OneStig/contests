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
        int n, k, m;
        cin >> n >> k >> m;
        string s;
        cin >> s;

        int seenc{}, count{};
        vector<bool> seen(k);
        string bad;

        for (int i = 0; i < m; i++) {
            if (s[i] - 'a' >= k) continue;

            if (!seen[s[i] - 'a']) {
                seenc++;
                seen[s[i] - 'a'] = 1;
            }

            if (seenc == k) {
                bad += s[i];
                count++;
                seenc = 0;

                for (int j = 0; j < k; j++) {
                    seen[j] = 0;
                }
            }
        }

        if (count >= n) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
            char c;

            for (int i = 0; i < k; i++) {
                if (!seen[i]) {
                    c = 'a' + i;
                    break;
                }
            }

            cout << bad;

            for (int i = 0; i < n - sz(bad); i++) {
                cout << c;
            }

            cout << '\n';
        }
    }
}
