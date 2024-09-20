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
        int q;
        cin >> q;

        int slen = 1, tlen = 1;
        bool sa = 1, ta = 1;

        while (q--) {
            int d, k;
            string x;
            cin >> d >> k >> x;

            if (d == 1) {
                slen += k * sz(x);
                if (sa) {
                    for (char& c : x) {
                        if (c != 'a') {
                            sa = 0;
                            break;
                        }
                    }
                }
            }
            else if (d == 2) {
                tlen += k * sz(x);
                if (ta) {
                    for (char& c : x) {
                        if (c != 'a') {
                            ta = 0;
                            break;
                        }
                    }
                }
            }

            if (!ta) {
                cout << "YES\n";
            }
            else {
                if (sa && slen < tlen) {
                    cout << "YES\n";
                }
                else {
                    cout << "NO\n";
                }
            }
        }
    }
}
