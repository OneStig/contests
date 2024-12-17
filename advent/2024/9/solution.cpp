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

    string s;
    cin >> s;

    vector<array<int, 2>> a(sz(s));
    for (int i = 0; i < sz(s); i++) {
        a[i][0] = s[i] - '0';
        a[i][1] = i / 2;
    }

    dbg(sz(s));

    int ans = 0;
    int pos = i;
    for (int i = 0; i < sz(s); i++) {
        auto cur = a[i];
        if (i % 2 == 0) {
            int targ = pos + cur[0];
            while (pos < targ) {
                ans += pos * cur[1];
                pos++;
            }
        }
        else {
            int found = -1;
            for (int j = sz(s) - 1; j > i; j--) {
                if (j % 2 == 0) {
                    if (a[j][0] <= cur[0]) {
                        found = j;
                        break;
                    }
                }
            }

            if (!found) {
                pos += cur[0];
            }
            else {
                for (int j = pos; j < pos + a[found][0]; j++) {
                    ans += j * a[found][1];

                }
                a[found][0] = 0;

            }
        }
    }
}
