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

const int e9 = 1e9;

uci main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        map<int, int> freq;

        while (n--) {
            int a;
            cin >> a;
            freq[a]++;
        }

        int q;
        cin >> q;

        while (q--) {
            int x, y;
            cin >> x >> y;
            int xx = abs(x), yy = abs(y);
            // a + b = x, a * b = y
            
            int ans{};
            if (y > 0) {
                int l = 1, r = xx / 2;
                while (l < r) {
                    int a = (l + r) / 2;
                    int b = xx - a;

                    if (a * b == y) {
                        l = a;
                        break;
                    }

                    if (a * b < y) {
                        l = a + 1;
                    }
                    else {
                        r = a - 1;
                    }
                }

                int aa = l, bb = xx - l;
                if (aa * bb == y) {
                    if (x < 0) {
                        aa = -aa;
                        bb = -bb;
                    }

                    if (aa == bb) {
                        ans = freq[aa] * (freq[aa] - 1) / 2;
                    }
                    else {
                        ans = freq[aa] * freq[bb];
                    }
                }
            }
            else {
                // wlog a < 0, b > 0
                int r = min(x - 1, -1ll);
                int l = r - e9;
                while (l < r) {
                    int a = (l + r) / 2;
                    int b = x - a;

                    if (a * b == y) {
                        l = a;
                        break;
                    }

                    if (a * b < y) {
                        l = a + 1;
                    }
                    else {
                        r = a - 1;
                    }
                }

                int aa = l, bb = x - l;
                if (aa * bb == y) {
                    ans = freq[aa] * freq[bb];
                }
            }

            cout << ans << ' ';
        }

        cout << '\n';
    }
}
