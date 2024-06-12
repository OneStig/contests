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
        int k, n;
        string s;
        cin >> n >> k >> s;

        vector<int> seg;
        vector<int> bad;
        int cs{};
        for (int i = 0; i < sz(s); i++) {
            cs++;
            if (i == sz(s) - 1 || s[i + 1] != s[i]) {
                if (cs != k) {
                    bad.push_back(sz(seg));
                }

                seg.push_back(cs);
                cs = 0;
            }
        }

        if (sz(bad) == 0) {
            cout << n << '\n';
            continue;
        }

        if (bad.back() == sz(seg) - 1) {
            // if there's more than 1 more bad seg, then we're screwed
            // otherwise, see if it can be broken to ammend the last one

            if (sz(bad) != 2 || seg[bad.back()] > k) {
                cout << -1 << '\n';
            }
            else {
                // color of bad.front must match bad.back
                int tot = seg[bad.front()] + seg[bad.back()];
                if (bad.front() % 2 == bad.back() % 2 && 
                    (tot == k || tot == 2 * k)) {
                    int idx = k - seg[bad.back()];

                    for (int j = 0; j < bad.front(); j++) {
                        idx += seg[j];
                    }

                    cout << idx << '\n';
                }
                else {
                    cout << -1 << '\n';
                }
            }
        }
        else {
            if (sz(bad) == 1 && seg[bad[0]] == 2 * k && sz(seg) % 2 == bad[0] % 2) {
                // 11000011 works, but 1100001100 doesn't
                // then when it works, find the correct indice;

                // 11110011 doesn't work either, because color is wrong

                int idx = k;

                for (int j = 0; j < bad[0]; j++) {
                    idx += seg[j];
                }

                cout << idx << '\n';
            }
            else {
                cout << -1 << '\n';
            }
        }
    }
}
