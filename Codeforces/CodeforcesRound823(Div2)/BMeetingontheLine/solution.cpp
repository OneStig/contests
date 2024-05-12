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

    int tc;
    cin >> tc;

    while (tc--) {
        int n;
        cin >> n;

        vector<array<int, 2>> ppl(n);

        for (auto& x : ppl) {
            cin >> x[0];
        }

        for (auto& x : ppl) {
            cin >> x[1];
        }

        sort(all(ppl));
        vector<int> pfx(n), sfx(n);

        pfx[0] = ppl[0][1];
        sfx[n - 1] = ppl[n - 1][1];

        for (int i = 1; i < n; i++) {
            pfx[i] = max(pfx[i - 1] + ppl[i][0] - ppl[i - 1][0], ppl[i][1]);
        }

        for (int i = n - 2; i >= 0; i--) {
            sfx[i] = max(sfx[i + 1] + ppl[i + 1][0] - ppl[i][0], ppl[i][1]);
        }


        ld ans{-1};
        ld mn = 1e18;

        if (n == 1) {
            cout << ppl[0][0] << '\n';
            continue;
        }

        for (int i = 1; i < n; i++) {
            int& a = ppl[i - 1][0], b = ppl[i][0];
            ld m;
            ld cost;

            if (sfx[i] >= pfx[i - 1] + b - a) {
                m = b - a;
                cost = sfx[i];
            }
            else if (pfx[i - 1] >= sfx[i] + b - a) {
                m = 0;
                cost = pfx[i - 1];
            }
            else {
                m = (ld)(sfx[i] - pfx[i - 1] + b - a) / 2;
                cost = pfx[i - 1] + m;
            }

            if (cost < mn) {
                mn = cost;
                ans = a + m;
            }

        }

        cout << setprecision(15) << ans << '\n';
    }
}
