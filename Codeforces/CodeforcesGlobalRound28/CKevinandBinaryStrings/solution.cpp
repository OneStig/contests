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
        cin >> s;
    
        int l1 = 1, r1 = sz(s);
        int l2 = 1, r2 = 1;
    
        int bz = -1;
        for (int i = 0; i < sz(s); i++) {
            if (s[i] == '0') {
                bz = i + 1;
                break;
            }
        }

        if (bz != -1) {
            int ts = sz(s) - bz + 1;
            vector<bool> best(ts);

            for (int l = 0; l + ts <= sz(s); l++) {
                vector<bool> cur(ts);
            
                for (int i = 0; i < ts; i++) {
                    cur[i] = s[l + i] != s[bz + i - 1];
                }

                bool better = false;

                for (int i = 0; i < ts; i++) {
                    if (best[i] != cur[i]) {
                        if (cur[i]) {
                            better = 1;
                        }
                        break;
                    }
                }

                if (better) {
                    best = cur;
                    l2 = l + 1;
                    r2 = l + ts;
                }
            }
        }
    
        cout << l1 << ' ' << r1 << ' ' << l2 << ' ' << r2 << '\n';
    }
}
